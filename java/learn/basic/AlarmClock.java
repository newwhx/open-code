public class AlarmClock{
	private int delay;
	private boolean flag;

	public AlarmClock(int dalay, boolean flag){
		this.delay = delay;
		this.flag = flag;
	}
	
	public void start(){
		class Printer implements ActionListener{
			public void actionPerformed(ActionEvent e){
				SimpleDateFormat format = new SimpleDateFormat("k:m:s");
				String result = format.format(new Data());
				System.out.println("The current time is " + result);
				if (flag) {
					Toolkit.getDefaultToolkit().beep();
				}
			}
		}
		new Timer(delay, new Printer()).start();
	}
} 
