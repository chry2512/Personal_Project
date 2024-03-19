import java.io.*;

public class App {
    public static void main(String[] args) throws Exception {
        FileWriter f  = new FileWriter("Agenda.txt");
        PrintWriter pw = new PrintWriter(f);
        String cognome;
        String nome;
        String telefono;
        String nPersone;
        int n;

        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader tastiera = new BufferedReader(input);

        System.out.println("Quante persone vuoi inserire?");

        try {

            int count= 1;

            nPersone = tastiera.readLine();
            n = Integer.valueOf(nPersone);
            Persona[] persone = new Persona[n];

            
            for(Persona p : persone){
                System.out.println("Inserisci il cognome: ");
                cognome = tastiera.readLine();
                System.out.println("Inserisci il nome: ");
                nome = tastiera.readLine();
                System.out.println("Inserisci il telefono: ");
                telefono = tastiera.readLine();
                p = new Persona(cognome, nome, telefono);
                System.out.print("Contatto n: " + count + "\n");
                p.stampaPersona();

                pw.println("Contatto n: " + count);
                pw.println("Cognome: " + p.getCognome());
                pw.println("Nome: " + p.getNome());
                pw.println("Telefono: " + p.getTelefono());
               
                count++;
            }
            pw.close();
           
            
        } catch (IOException e) {
            System.err.println("Errore di Input");
            e.printStackTrace();
        }

       
    }
}
