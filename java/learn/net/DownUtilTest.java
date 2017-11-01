public class DownUtilTest {
	public static void main(String[] args)throws Exception {
		System.out.println(Integer.getInteger(args[0]));

		final DownUtil downUtil = new DownUtil("https://download.fedoraproject.org/pub/fedora/linux/releases/26/Workstation/x86_64/iso/Fedora-Workstation-Live-x86_64-26-1.5.iso", "Fedora.iso", Integer.parseInt(args[0]));
		downUtil.download();
		new Thread(()->{
			while(downUtil.getCompleteRate() < 1){
				System.out.println("已完成: " + 100 * downUtil.getCompleteRate() + "%");
				try {
					Thread.sleep(5000);
				} catch(Exception e){
					e.printStackTrace();
				}
			}
		}).start();
	}
}
