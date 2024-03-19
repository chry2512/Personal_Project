public class App {
    public static void main(String[] args) throws Exception {

        int matrice[][] = new int[3][3];
        System.out.println("***************Inizializzazione Matrice con Valori Random***************");

        for (int riga = 0; riga < 3; riga++) {
            for (int colonna = 0; colonna < 3; colonna++) {
                matrice[riga][colonna] = (int) (Math.random() * 10);
                System.out.print(matrice[riga][colonna] + " ");

            }
            System.out.println();
        }

    }
}
