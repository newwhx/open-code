public class ThreadTest {
	public static void main(String[] args) {
		new MyThread().start();
	}
}

class MyThread extends Thread{
	int count = 10;
	public void run(){
		while(0 != count){
		        System.out.println(count + " ");
			count--;
		}
	}
}
