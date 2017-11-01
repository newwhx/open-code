import java.net.*;
import java.io.*;

public class Server {
		public static void main(String[] args) throws Exception {
				ServerSocket ss = new ServerSocket(3000);
				while (true) {
						Socket s = ss.accept();
						PrintStream ps = new PrintStream(s.getOutputStream());
						ps.println("您好，你收到来自服务器的问候！");
						ps.close();
						s.close();
				}
		}
}
