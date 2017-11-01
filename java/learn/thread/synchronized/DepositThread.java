public class DepositThread implements Runnable {
	private int i = 0;
	private Account account;
	private double depositAmount;
	public DepositThread(Account account, double depositAmount){
		this.account = account;
		this.depositAmount = depositAmount;
	}

	public synchronized void run(){
		for (; i < 100; i++) {
			System.out.println(Thread.currentThread().getName() + " :" + i);
			account.deposit(depositAmount);
		}
	}
}
