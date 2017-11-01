public class CompileClassLoader extends ClassLoader {
	private byte[] getBytes(String filename) throws IOException{
		File file = new File(filename);
		long len = file.length();
		byte[] raw = new byte[(int)len];
		try (
			FileInputStream fin = new FileInputStream(file))
		{
				int r = fin.read(raw);
				if (r != len) throw new IOException("cant read all files:" + r + " != " + len); 
				return raw;
		}
	}

	private boolean compile(String javaFile) throws IOException {
		System.out.println("compile class loader: being compile " + javaFile + "...");	
	}
}
