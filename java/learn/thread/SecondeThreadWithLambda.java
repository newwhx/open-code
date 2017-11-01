public class SecondeThreadWithLambda{
	int i = 0;
	public static void main(String[] args) {
		for (int i = 0; i < 3; i++) {
			System.out.println(Thread.currentThread().getName() + " " + i);
			if (2 == i) {
				new Thread(() -> System.out.println(Thread.currentThread().getName())).start();
			}
		}
	}
}
