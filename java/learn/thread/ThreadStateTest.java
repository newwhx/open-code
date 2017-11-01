public class ThreadStateTest {
	public static void main(String[] args) throws InterruptedException {
		ThreadState state = new ThreadState();
		Thread thread = new Thread(state);
		System.out.println("新建thread: " + thread.getState());
		thread.start();
		System.out.println("启动thread, 调用start()方法: " + thread.getState());
		System.out.println("0调用start()方法: " + thread.getState());
		System.out.println("1调用start()方法: " + thread.getState());
		System.out.println("2调用start()方法: " + thread.getState());
		thread.sleep(100);
		System.out.println("休眠0.1秒 thread: " + thread.getState());
		thread.sleep(1000);
		System.out.println("休眠1秒 thread: " + thread.getState());
		thread.notify();//notifyNow();
		System.out.println("调用state类的notifyNow thread: " + thread.getState());
		thread.sleep(1000);
		System.out.println("再次休眠1秒 thread: " + thread.getState());
		thread.sleep(1000);
		System.out.println("再次休眠1秒 thread: " + thread.getState());
	}
}

class ThreadState implements Runnable {
	public synchronized void waitForASecond() throws InterruptedException {
		System.out.println("In wait for a second to wait");
		wait(500);
	}
	public synchronized void waitForYears()throws InterruptedException {
		System.out.println("In wait for years to wait");
		wait();
	}
	public synchronized void notifyNow() throws InterruptedException {
		System.out.println("In notify now to notify");
		notify();
	}
	public void run() {
		try {
			waitForASecond();
			waitForYears();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
}
