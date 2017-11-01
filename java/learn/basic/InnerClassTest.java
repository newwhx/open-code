public class InnerClassTest{
	public static void main(String[] args) {
		Outter out = new Outter();
		Outter.Inner inner = out.new Inner();
		System.out.println("Get inner class instance");

		Outter.Inner inner1 = out.doit();

		Outter.Inner inner2 = Outter.getInnerInstance();
	}
}

