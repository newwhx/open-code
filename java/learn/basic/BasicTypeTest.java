public class BasicTypeTest{
	public static void main(String[] args) {
		int a = 78, b = 36;
		int c[][] = new int[5][6];
		for (int i = 0; i < c.length; i++) {
			for (int j = 0; j < c[i].length; j++) {
				System.out.println(c[i][j]);	
			}
		}
		
		String str = "abc";
		String str1 = "abc";
		String str2 = new String("abc");
		System.out.println(str == str1);
		System.out.println(str == str2);
		System.out.println(str1 == str2);
		System.out.println(str.equals(str1));
		Object o = new Integer(2);
		System.out.println((String)o);
	}
}
