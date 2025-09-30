public class ModuleLoader implements Runnable {

    private String modulo;
    private int milissegundos;
    private ServerInitializer server;

    public ModuleLoader(String modulo, ServerInitializer server, int milissegundos) {
        this.modulo = modulo;
        this.milissegundos = milissegundos;
        this.server = server;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(milissegundos);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Módulo de " + modulo + " Carregado.");
        server.getLatch().countDown();
    }
}
