import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class TCPServer {
    public static void main(String[] args) {
        try {
            ServerSocket servidor = new ServerSocket(12345);
            System.out.println("Servidor escutando na porta 12345!");

            while (true) {
                Socket conn = servidor.accept();
                System.out.println("Cliente conectado: " + conn.getInetAddress().getHostAddress());
                ObjectOutputStream saida = new ObjectOutputStream(conn.getOutputStream());
                saida.flush();
                saida.writeObject(new Date());
                saida.close();
                conn.close();
            }

        } catch (Exception e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}