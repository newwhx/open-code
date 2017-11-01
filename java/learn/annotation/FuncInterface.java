@FunctionalInterface
public interface FuncInterface{
		static void foo1(){
				System.out.println("foo class method");
		}

		static void foo2(){}

		default void bar1(){}

		default void bar(){
				System.out.println("bar default class");
		}

		void test();
		//void test1();
}
