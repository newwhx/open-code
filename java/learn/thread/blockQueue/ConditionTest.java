import java.util.concurrent.*;
public class ConditionTest {
	public static void main(String[] args) {
		BlockingQueue<String> bq = new ArrayBlockingQueue<>(1);
		new Producer("甲", bq).start();
		new Producer("乙", bq).start();
		new Producer("丙", bq).start();
		new Consumer("A", bq).start();
	}
}
