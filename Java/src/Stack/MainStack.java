package Stack;

public class MainStack {

	public static void main(String[] args) {
		
		Stack stack = new Stack();
		
		stack.push(1);
		stack.push(2);
		stack.push(3);
		
		stack.traverse();
		
		System.out.println("Popped "+ stack.pop());
		
		
		stack.traverse();
	}

}
