import java.util.concurrent.*;
public class Consumer extends Thread{

	private BlockingQueue<String> bq;

	public Consumer(String name, BlockingQueue<String> bq) {
		super(name);
		this.bq = bq;
	}

	public void run(){
		while(true){
			//System.out.println(getName() + "消费者准备消费集合元素");
			try {
				Thread.sleep(200);
				bq.take();
			} catch(Exception e){
				e.printStackTrace();
			}
			System.out.println(getName() + "消费完成: " + bq);
		}
	}

}
