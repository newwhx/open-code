import java.net.*;
import java.io.*;
public class DownUtil {

	private String path;
	private String targetFile;
	private int threadNum;

	private DownThread[] threads;
	private int fileSize;

	public DownUtil(String path, String targetFile, int threadNum) {
		this.path = path;
		this.targetFile = targetFile;
		this.threadNum = threadNum;

		threads = new DownThread[threadNum];
		this.fileSize = 0;
	}

	public void download() throws Exception {
		URL url = new URL(path);
		HttpURLConnection conn = (HttpURLConnection) url.openConnection();
		conn.setConnectTimeout(5000);
		conn.setRequestMethod("GET");
		conn.setRequestProperty(
				"Accept",
				"image/gif,image/jpeg, image/pjpeg, image/pjpeg, " + 
				"application/x-shockwave-flash, application/xaml+xml, " +
				"application/vnd.ms-xpsdocument, application/x-ms-xbap, " + 
				"application/x-ms-application, application/vnd.ms-excel, " +
				"application/vnd.ms-powerpoint, application/msword, */*");
		conn.setRequestProperty("Accept-Language", "zh-CN");
		conn.setRequestProperty("Charset","UTF-8");
		conn.setRequestProperty("Connection", "keep-alive");

		fileSize = conn.getContentLength();
		conn.disconnect();
		int currentPartSize = fileSize / threadNum + 1;
		RandomAccessFile file = new RandomAccessFile(targetFile, "rw");

		file.setLength(fileSize);
		file.close();
		for (int i = 0; i < threadNum; i++) {
			int startPos = i * currentPartSize;
			RandomAccessFile currentPart = new RandomAccessFile(targetFile, "rw");
			currentPart.seek(startPos);
			threads[i] = new DownThread(startPos, currentPartSize, currentPart);
			threads[i].start();
		}
	}

	public double getCompleteRate() {
		int sumSize = 0;
		for (int i = 0; i < threadNum; i++) {
			sumSize += threads[i].length;
		}
		return (sumSize * 1.0 / fileSize);
	}

	private class DownThread extends Thread{
		private int startPos;
		private int currentPartSize;
		private RandomAccessFile currentPart;
		public int length;

		public DownThread(int startPos, int currentPartSize, RandomAccessFile currentPart){
			this.startPos = startPos;
			this.currentPartSize = currentPartSize;
			this.currentPart = currentPart;
		}

		public void run(){
			try {
				URL url = new URL(path);
				HttpURLConnection conn = (HttpURLConnection) url.openConnection();
				conn.setConnectTimeout(5000);
				conn.setRequestMethod("GET");
				conn.setRequestProperty(
						"Accept",
						"image/gif,image/jpeg, image/pjpeg, image/pjpeg, " +
						"application/x-shockwave-flash, application/xaml+xml, " +
						"application/vnd.ms-xpsdocument, application/x-ms-xbap, " +
						"application/x-ms-application, application/vnd.ms-excel, " +
						"application/vnd.ms-powerpoint, application/msword, */*");
				conn.setRequestProperty("Accept-Language", "zh-CN");
				conn.setRequestProperty("Charset","UTF-8");

				InputStream in = conn.getInputStream();
				in.skip(this.startPos);
				byte[] buffer = new byte[1024];

				int hasRead = 0;

				System.out.println(getName() + "run success");

				while (length < currentPartSize
				    && (hasRead = in.read(buffer)) != -1) {
					currentPart.write(buffer, 0, hasRead);
					length += hasRead;
					//System.out.println(getName() + "下载完成" + length);

				}

				currentPart.close();
				in.close();

			} catch(Exception e){
				e.printStackTrace();
			}
		}

	}
}
