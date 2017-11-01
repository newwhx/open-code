import java.util.*;

public class SafeVarargsTest {
		public static void main(String[] args) {
			MySafeVarargsClass.faultMethod(Arrays.asList("Hello!"), Arrays.asList("world"));	
		}
}

class MySafeVarargsClass {
		@SafeVarargs //如果没有这个Annotation，编译的会报编译告警
		public static void faultMethod(List<String>... listArray){
				List[] lstArray = listArray;
				List<Integer> myList = new ArrayList<Integer>();
				myList.add(new Random().nextInt(100));
		}
}
