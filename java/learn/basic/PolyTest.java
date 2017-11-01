public class PolyTest {
	public static void main(String[] args) {
		Father p = new Child();
		p.getAge();
		System.out.println(p.age);
	}
}

class Father {
	int age = 40;

	public void getAge() {
		System.out.println(age);
	}
	
}

class Child extends Father {
	int age = 20;

	public void getAge() {
		System.out.println(age+", "+ super.age);
	}
}
