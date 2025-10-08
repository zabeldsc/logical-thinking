import java.util.concurrent.CountDownLatch;

public class ServerInitializer {

    private CountDownLatch latch = new CountDownLatch(4);

    void awaitForInitialization() throws InterruptedException {
        latch.await();
    };

    void startServer() {
        System.out.println("Servidor Principal Online: Pronto para aceitar conexões (Socket.bind())");
    }

    CountDownLatch getLatch() {
        return latch;
    }

    void setLatch(CountDownLatch latch) {
        this.latch = latch;
    }
}