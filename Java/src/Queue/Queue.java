package Queue;

import LinkedLists.SingularNode;

public class Queue {
	
	private SingularNode head;
	
	private SingularNode tail;
	
	private int size = 0;
	
	public Queue() {
		this.head = null;
		this.tail = null;
	}
	
	public void Enqueue(int value) {
		
		SingularNode node = new SingularNode(value);
			
		if(isEmpty()) {
			this.head = node;
			this.tail = node;
		} else {
			this.tail.setNext(node);
			this.tail = node;	
		}
		this.size++;
	}
	
	public int Dequeue() {
		
		int value = -1;
		
		if(isEmpty())
			return value;
		if(this.size == 1) {
			value = this.head.getValue();
			this.head = null;
			this.tail = null;
		}else {
			value = this.head.getValue();
			this.head = this.head.getNext();
		}
		this.size--;
		return value;
		
	}
	
	public void traverse() {
		SingularNode iter = this.head;
		
		while(iter != null) {
			System.out.println(iter.getValue());
			iter = iter.getNext();
		}
	}
	
	public int peek() {
		if(!isEmpty())
			return this.head.getValue();
		else
			return -1;
	}
	
	public boolean isEmpty() {
		return this.size == 0;
	}

}
