import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
    public static <T> void main(String[] args) throws InterruptedException {
        ExecutorService executorService = Executors.newCachedThreadPool();
        ServerInitializer server = new ServerInitializer();
        executorService.submit(new ModuleLoader("Configuracao", server, 2000));
        executorService.submit(new ModuleLoader("Seguranca", server, 10000));
        executorService.submit(new ModuleLoader("Logs", server, 1000));
        executorService.submit(new ModuleLoader("Cache", server, 3000));
        server.awaitForInitialization();
        server.startServer();
    }
}
