import java.net.*;
import java.io.*;

public class Client extends Thread{
		public static void main(String[] args) {
				for (int i = 0; i < 5; i++) {
						new Client().start();
				}
		}	

		public void run(){
				try{
						Socket s = new Socket("127.0.0.1", 3000);
						BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
						String line = br.readLine();
						System.out.println(getName() + "接收到来自服务器的数据: " + line);

						br.close();
						s.close();
				}catch(Exception e){e.printStackTrace();}
		}
}
