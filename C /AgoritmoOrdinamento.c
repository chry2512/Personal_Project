#include <stdio.h>

// Bubble Sort
// Sconsigliato  
// confronta coppie di elementi adiacenti e li scambia se sono nel posto sbagliato
/*
    Bubble Sort e Selection Sort, pur essendo semplici da capire e implementare, 
    hanno una complessità temporale di O(n^2), 
    rendendoli inefficienti per grandi set di dati. 
    Invece, l'Insertion Sort, pur avendo la stessa complessità temporale, 
    è generalmente più efficiente su piccoli set di dati o dati quasi ordinati, 
    rendendolo una scelta preferibile in tali situazioni.
*/

void bubbleSort(int arr[], int n) {

    for(int i=0; i<n-1; i++) {     

        for (int j=0; j<n-i-1; j++) { 

           if (arr[j] > arr[j+1]) {
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
           }
        }
   }
}

/* Selection Sort
// Sconsigliato 
# L'algoritmo di Selection Sort funziona selezionando ripetutamente l'elemento minimo
# dal segmento non ordinato della lista e scambiandolo con il primo elemento non ordinato.
# Questo processo continua fino a quando tutti gli elementi sono ordinati.
# Nonostante la sua semplicità, ha una complessità temporale di O(n^2), 
# il che lo rende inefficiente su grandi liste.
/*
    Bubble Sort e Selection Sort, pur essendo semplici da capire e implementare, 
    hanno una complessità temporale di O(n^2), 
    rendendoli inefficienti per grandi set di dati. 
    Invece, l'Insertion Sort, pur avendo la stessa complessità temporale, 
    è generalmente più efficiente su piccoli set di dati o dati quasi ordinati, 
    rendendolo una scelta preferibile in tali situazioni.
*/

void selectionSort(int arr[], int n) {
    for(int i = 0; i<n; i++) {

       int min = i;

        for(int j = i+1; j<n; j++){
           if(arr[j] < arr[min])
            min = j;
        }

      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
}

/*Insertion Sort
// consigliabile per piccoli array
# L'algoritmo di Insertion Sort funziona dividendo la lista in una parte ordinata e una non ordinata.
# All'inizio, l'elemento più a sinistra è considerato ordinato. Poi, prende un elemento dalla parte non ordinata
# e lo inserisce nella posizione corretta nella parte ordinata, spostando gli elementi necessari.
# Questo processo continua fino a quando tutti gli elementi sono ordinati.
# Ha una complessità temporale di O(n^2), il che lo rende inefficiente su grandi liste.
# Tuttavia, è efficiente per le liste quasi ordinate e ha un buon comportamento in caso di liste di piccole dimensioni.
*/

void insertionSort(int arr[], int n) {

    for(int i = 1; i<n; i++) {

      int key = arr[i];
      int j = i-1;

      while(j >= 0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j = j-1;
      }

      arr[j+1] = key;
    }
}

/*
 Quick sort
 preferibile per array grande con memoria limitata , al massimo degrada a una complessità come quella di Insertion Sort O(n^2)
 # L'algoritmo Quick Sort è un algoritmo di ordinamento efficiente con complessità temporale media di O(n log n).
 # Funziona sulla base del principio "divide et impera". Sceglie un elemento "pivot" dalla lista,
 # poi riordina la lista in modo che tutti gli elementi minori del pivot siano posti prima di esso,
 # e tutti gli elementi maggiori siano posti dopo. Questo processo è chiamato "partitioning".
 # Successivamente, l'algoritmo esegue ricorsivamente lo stesso processo sulle due sottoliste create.
 # Nonostante la sua efficienza in media, nel caso peggiore ha una complessità temporale di O(n^2).
*/ 

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}




/*Merge Sort
// complesso per array di grandi dimensioni
// attenzione allo spazio di memoriaù
# L'algoritmo Merge Sort è un algoritmo di ordinamento efficiente con complessità temporale di O(n log n).
# Funziona sulla base del principio "divide et impera". Prima divide la lista in due metà,
# poi ordina ciascuna metà ricorsivamente, e infine unisce le due metà ordinate in una singola lista ordinata.
# L'unione viene effettuata in modo tale da mantenere l'ordine degli elementi.
# Questo algoritmo è stabile (mantiene l'ordine relativo degli elementi uguali) e ha un buon comportamento
# su liste di qualsiasi dimensione. Tuttavia, richiede spazio di memoria addizionale per l'operazione di unione.
*/

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


