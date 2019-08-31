package Stack;

import LinkedLists.SingularNode;

public class Stack {
	
	private SingularNode head;
	
	private int size = 0;
	
	public void push(int value) {
		
		SingularNode node = new SingularNode(value);
		
		if(isEmpty()) {
			head = node;
		}else {
			node.setNext(head);
			head = node;
		}
		this.size++;
		
	}
	
	public int pop() {
		
		if(isEmpty())
			return -1;
		
		int currValue = this.head.getValue();
		head = head.getNext();
		
		this.size--;
		
		return currValue;
	}
	
	public int peek() {
		if(!isEmpty())
			return this.head.getValue();
		else
			return -1;
	}
	
	public void traverse() {
		
		SingularNode iter = this.head;
		while(iter != null) {	
			System.out.println(iter.getValue());
			iter = iter.getNext();	
		}
	}
	
	public boolean isEmpty() {
		return this.size == 0;
	}
	
	
	

}
