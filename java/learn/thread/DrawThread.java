public class DrawThread extends Thread {
	private Account account;
	private double drawAmount;
	
	public DrawThread(String name, Account account, double drawAmount){
		super(name);
		this.account = account;
		this.drawAmount = drawAmount;
	}

	public void run() {
	    synchronized(account){
		if (account.getBalance() >= drawAmount) {
			System.out.println(getName() + "取钱成功！吐出查票：" + drawAmount);
			try {
				Thread.sleep(1);
			} catch(Exception e){
				e.printStackTrace();
			}
			
			account.setBalance(account.getBalance() - drawAmount);
			System.out.println("\t余额为: " + account.getBalance());
		}
		else{
			System.out.println(getName() + "取钱失败，余额不足");
		}
	    }
	}
}
