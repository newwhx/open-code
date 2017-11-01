import java.io.*;
public class Account {

	private String accountNo;
	private double balance;
	private boolean flag = false;
	public Account(){}

	public Account(String accountNo){
		this.accountNo = accountNo;
		this.balance = 0;
	}

	public Account(String accountNo, double balance) {
		this.accountNo = accountNo;
		this.balance = balance;
	}

	public void setAccountNo(String accountNo) {
		this.accountNo = accountNo;
	}

	public String getAccountNo() {
		return accountNo;
	}

	public void setBalance(double balance) {
		this.balance = balance;
	}

	public double getBalance() {
		return balance;
	}

	/*
	 * 取钱
	 */
	public synchronized void draw(double drawAmount) {
		try {
			// 如果账户没钱，或者余额不够要取的前，则返回不取了
			if (!flag || drawAmount > getBalance()) {
				wait();
			}else{
				balance -= drawAmount;
				System.out.println(Thread.currentThread().getName()+" 取钱: " + drawAmount + " , 余额：" + getBalance());
				flag = (balance != 0);
				notifyAll();
			}

		} catch(InterruptedException e){
			e.printStackTrace();
		}
	}

	public synchronized void deposit(double depositAmount) {
		try {
			if (flag) {
				wait();
			}else{
				balance += depositAmount;
				flag = true;
				System.out.println(Thread.currentThread().getName()+" 存钱: " + depositAmount + ", 余额： " + getBalance());
				notifyAll();
			}

		} catch(InterruptedException e){
			e.printStackTrace();
		}
	}



}
