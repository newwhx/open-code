public class FirstThread extends Thread {
	private static int i = 0;//线程安全的问题
	public void run() {
		for (;  i < 10; i++) {
			System.out.println(getName() + " " + i);	
		}
	}
	
	public static void main(String[] args) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				new FirstThread().start();
			}
		}
	}
}
