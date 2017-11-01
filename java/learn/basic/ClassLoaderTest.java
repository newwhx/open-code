import java.net.*;
import java.util.*;
import java.io.*;
public class ClassLoaderTest {
	public static void main(String[] args) throws IOException {
		ClassLoader sl = ClassLoader.getSystemClassLoader();
		System.out.println("class loader : " + sl);

		Enumeration<URL> eml = sl.getResources("");
		while(eml.hasMoreElements()){
			System.out.println(eml.nextElement());
		}

		ClassLoader el = sl.getParent();
		System.out.println("extension class loader :" + el);
		System.out.println("extension class path:" + System.getProperty("java.ext.dirs"));
		System.out.println("parent of externsion class loader: " + el.getParent());
		
	}
}
