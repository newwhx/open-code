public class Outter{
	class Inner{
	}

	public Inner doit(){
		return new Inner();
	}

	public static Outter getInstance(){
		return new Outter();
	}

	public static Inner getInnerInstance(){
		return new Inner();
	}

} 

