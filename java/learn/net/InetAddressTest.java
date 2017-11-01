import java.net.*;

public class InetAddressTest {
	public static void main(String[] args)throws Exception {
		InetAddress ip = InetAddress.getByName("www.baidu.com");
		System.out.println("baidu是否可达：" + ip.isReachable(4000));
		System.out.println(ip.getHostAddress());
		System.out.println("baidu的全限定名: " + ip.getCanonicalHostName());

		InetAddress local = InetAddress.getByAddress(new byte[]{127,0,0,1});
		System.out.println("local是否可达：" + local.isReachable(4000));
		System.out.println("local的全限定名: " + local.getCanonicalHostName());
	}
}
