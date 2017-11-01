import java.io.*;

public class InputStreamTest {
	public static void main(String[] args) throws IOException {
		byte[] b = new byte[32];
		File f = new File("test.txt");
		InputStream input = new FileInputStream(f);
		int tmp = 0;
		//while((tmp = input.read()) != -1){
			//System.out.println(tmp);
		//}
		while((tmp = input.read(b)) != -1){
			System.out.println(tmp + ": " +  new String(b));
		}
	}
}
