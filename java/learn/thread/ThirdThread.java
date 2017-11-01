import java.util.concurrent.*;

public class ThirdThread {
	public static void main(String[] args) {
		ThirdThread tt = new ThirdThread();

		FutureTask<Integer> task = new FutureTask<Integer>((Callable<Integer>)()->{
			int i = 0;
			for (; i < 10; i++) {
				System.out.println(Thread.currentThread().getName() + " " + i); }
			return i;
		});

		for (int i = 0; i < 6; i++) {
			System.out.println(Thread.currentThread().getName() + " " + i);
			if (i % 2 == 0){
				new Thread(task, "thread-" + i).start();
				new Thread(task, "thread-" + i).start();
			}
		}

		try {
			System.out.println("sub thread returned value: " + task.get());
		} catch(Exception e){
			e.printStackTrace();
		}
	}
}
