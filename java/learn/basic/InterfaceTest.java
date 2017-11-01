public class InterfaceTest implements MyInerface {
	public int getMuilt(int c, int d){
		return c*d;
	}

	public int getSum(int a, int b){
		return (a + b);
	}
	
	public static void main(String[] args) {
		InterfaceTest it = new InterfaceTest();
		System.out.println(it.getSum(a, b));
		//a = 5;
		//b = 6;
		System.out.println(it.getMuilt(a, b));
	}
}
interface MyInerface{
	int a = 3;

	int b = 4;

	public int getSum(int c, int d);
	public int getMuilt(int c, int d);
}
