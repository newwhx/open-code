public class StaticTest {
	static{
	
		b = 6;
		System.out.println("In StaticTest: static block");
	}

	static int a = 5;
	static int b = 9;
	static int c;

	public static void main(String[] args) {
		//System.out.println("in main method, b = " + b);
		//System.out.println(X.name);
		//X x = new X();
		//x.a++;
		//System.out.println("x.a = " + x.a);
		//X.a++;
		//System.out.println("X.a = " + X.a);
		try {
			Class.forName("X");
		} catch(Exception e){
			e.printStackTrace();
		}
		
		Class x = new X().getClass();
	}
}

class X {
	static int a  = 6;
	static String name = "Hello world";
	static{
		System.out.println("In X: static block");
	}

	X(){
		System.out.println("In the construct");
	}

}
