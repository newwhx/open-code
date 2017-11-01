public class SecondeThread implements Runnable {
	private int i;

	public void run() {
		for (; i < 10; i++) {
		    System.out.println(Thread.currentThread().getName() + " " + i);
		}
	}
	
	public static void main(String[] args) {
		for (int i = 0; i < 3; i++) {
			System.out.println(Thread.currentThread().getName() + " " + i);
			if (2 == i) {
				SecondeThread st = new SecondeThread();
				new Thread(st).start();
				new Thread(st).start();
			}
		}
	}
}
