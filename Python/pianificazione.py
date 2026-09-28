import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.patches import Patch
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg 
from tkinter import Tk, filedialog, messagebox, simpledialog
from datetime import datetime, timedelta
import random

# Funzione per calcolare la pianificazione evitando sovrapposizioni
def calcola_pianificazione(df):
    sviluppatori = df['Assignee'].unique()
    pianificazione = []

    for sviluppatore in sviluppatori:
        tasks = df[df['Assignee'] == sviluppatore]
        start_date = datetime(2025, 1, 1)
        for _, task in tasks.iterrows():
            end_date = start_date + timedelta(days=task['Effort'])
            pianificazione.append({
                'Assignee': sviluppatore,
                'Issue Key': task['Issue Key'],
                'Summary': task['Summary'],
                'Start Date': start_date,
                'End Date': end_date
            })
            start_date = end_date  # Aggiorna la data di inizio per il prossimo task

    return pd.DataFrame(pianificazione)

# Funzione per mostrare il calendario
def mostra_calendario(pianificazione_df, root):
    fig, ax = plt.subplots(figsize=(14, 10))
    colori = {}  # Colori per ogni sviluppatore
    y_labels = []
    y_ticks = []
    legend_patches = []

    for idx, sviluppatore in enumerate(pianificazione_df['Assignee'].unique()):
        colore = plt.cm.get_cmap('tab10')(random.random())  # Colore casuale
        colori[sviluppatore] = colore
        y_labels.append(sviluppatore)
        y_ticks.append(idx)
        
        # Calcolo dei giorni totali per lo sviluppatore
        giorni_totali = pianificazione_df[pianificazione_df['Assignee'] == sviluppatore].apply(
            lambda row: (row['End Date'] - row['Start Date']).days, axis=1
        ).sum()

        legend_patches.append(Patch(color=colore, label=f"{sviluppatore} ({giorni_totali} giorni)"))

    for idx, row in pianificazione_df.iterrows():
        y_pos = y_ticks[y_labels.index(row['Assignee'])]
        start_day = (row['Start Date'] - datetime(2025, 1, 1)).days
        end_day = (row['End Date'] - datetime(2025, 1, 1)).days
        ax.barh(y_pos, end_day - start_day, left=start_day, color=colori[row['Assignee']],
                edgecolor='black', label=row['Assignee'])

    # Configura l'asse y con i nomi degli sviluppatori
    ax.set_yticks(y_ticks)
    ax.set_yticklabels(y_labels, fontsize=9)  # Ridotta dimensione del testo
    ax.invert_yaxis()  # Ordina dall'alto verso il basso

    # Configura l'asse x con i giorni
    ax.set_xticks(range(0, 366, 50))  # Scala dei giorni ogni 50
    ax.set_xticklabels(range(0, 366, 50), fontsize=10)
    ax.set_xlabel("Giorni", fontsize=12)
    ax.set_title("Pianificazione delle attività", fontsize=14)

    # Legenda per i colori degli sviluppatori
    ax.legend(handles=legend_patches, title="Sviluppatori", loc='upper right', fontsize=10)

    # Mostra il grafico nella finestra Tkinter
    canvas = FigureCanvasTkAgg(fig, master=root)
    canvas.draw()
    canvas.get_tk_widget().pack()

# Funzione per modificare un task
def modifica_task(assignee, issue_key, summary, start_date, end_date, pianificazione_df, root):
    messagebox.showinfo("Informazioni Task", 
                        f"Assignee: {assignee}\n"
                        f"Issue Key: {issue_key}\n"
                        f"Summary: {summary}\n"
                        f"Start Date: {start_date.strftime('%Y-%m-%d')}\n"
                        f"End Date: {end_date.strftime('%Y-%m-%d')}")

    nuova_start_date = simpledialog.askstring("Modifica Task", 
                                              f"Data di Inizio (YYYY-MM-DD) attuale: {start_date.strftime('%Y-%m-%d')}\n"
                                              "Inserisci nuova data di inizio:")
    nuova_end_date = simpledialog.askstring("Modifica Task", 
                                            f"Data di Fine (YYYY-MM-DD) attuale: {end_date.strftime('%Y-%m-%d')}\n"
                                            "Inserisci nuova data di fine:")

    try:
        if nuova_start_date:
            nuova_start_date = datetime.strptime(nuova_start_date, '%Y-%m-%d')
        else:
            nuova_start_date = start_date
        if nuova_end_date:
            nuova_end_date = datetime.strptime(nuova_end_date, '%Y-%m-%d')
        else:
            nuova_end_date = end_date

        if nuova_start_date >= nuova_end_date:
            messagebox.showerror("Errore", "La data di inizio deve essere precedente alla data di fine.")
            return

        # Modifica il DataFrame
        task_idx = (pianificazione_df['Assignee'] == assignee) & (pianificazione_df['Issue Key'] == issue_key)
        pianificazione_df.loc[task_idx, 'Start Date'] = nuova_start_date
        pianificazione_df.loc[task_idx, 'End Date'] = nuova_end_date

        messagebox.showinfo("Successo", "Task modificato con successo!")
    except ValueError:
        messagebox.showerror("Errore", "Formato della data non valido. Usa il formato YYYY-MM-DD.")

# Funzione principale per avviare il programma
def avvia_programma():
    # Crea la finestra principale
    root = Tk()
    root.title("Pianificazione Attività")

    # Carica il file CSV
    file_path = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
    if not file_path:
        return

    df = pd.read_csv(file_path)

    # Verifica le colonne richieste
    colonne_richieste = ['Issue Key', 'Summary', 'Effort', 'Assignee']
    if not all(col in df.columns for col in colonne_richieste):
        messagebox.showerror("Errore", f"Il file CSV deve contenere le colonne: {', '.join(colonne_richieste)}")
        return

    # Sostituisci i valori NaN nella colonna 'Effort' con 0 e converte in int
    df['Effort'] = df['Effort'].fillna(0).astype(int)

    # Calcola la pianificazione iniziale
    pianificazione_df = calcola_pianificazione(df)

    # Mostra il calendario grafico
    mostra_calendario(pianificazione_df, root)

    # Funzione per gestire il click sulla barra
    def on_click(event):
        x_pos = event.xdata
        if x_pos is None:
            return
        for _, row in pianificazione_df.iterrows():
            start = (row['Start Date'] - datetime(2025, 1, 1)).days
            end = (row['End Date'] - datetime(2025, 1, 1)).days
            if start <= x_pos <= end:
                modifica_task(row['Assignee'], row['Issue Key'], row['Summary'], row['Start Date'], row['End Date'], pianificazione_df, root)
                break

    fig = plt.gcf()
    fig.canvas.mpl_connect('button_press_event', lambda event: on_click(event))

    root.mainloop()

# Avvia il programma
if __name__ == "__main__":
    avvia_programma()
