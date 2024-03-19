public class Persona {

    private String cognome;
    private String nome;
    private String telefono;

    public Persona() {
        this.cognome = "";
        this.nome = "";
        this.telefono = "";
    }

    public Persona(String cognome, String nome, String telefono) {
        this.cognome = cognome;
        this.nome = nome;
        this.telefono = telefono;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getCognome() {
        return this.cognome;
    }       

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getTelefono() {
        return this.telefono;
    }

    public void stampaPersona(){
        System.out.println("Cognome: " + this.cognome);
        System.out.println("Nome: " + this.nome);
        System.out.println("Telefono: " + this.telefono);
    }
}