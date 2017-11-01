import java.net.*;

public class URLEDecoderTest {
	public static void main(String[] args)throws Exception {
		String keyword = URLDecoder.decode("%E7%96%AF%E7%8B%82java", "utf-8");
		System.out.println(keyword);

		String urlStr = URLEncoder.encode("中国共产党第十九次代表大会success", "GBK");
		System.out.println(urlStr);

		urlStr = URLEncoder.encode("中国共产党第十九次代表大会success", "utf-8");
		System.out.println(urlStr);
	}
}
