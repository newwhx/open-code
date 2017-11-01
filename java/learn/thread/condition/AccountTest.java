public class AccountTest {
	public static void main(String[] args) {
		Account acc = new Account("1234567", 0);
		new DrawThread("取钱甲", acc, 800).start();
		new DrawThread("取钱乙", acc, 800).start();
		DepositThread dt = new DepositThread(acc, 800);
		new Thread(dt, "存钱甲").start();
		new Thread(dt, "存钱乙").start();
		new Thread(dt, "存钱丙").start();
	}
}
