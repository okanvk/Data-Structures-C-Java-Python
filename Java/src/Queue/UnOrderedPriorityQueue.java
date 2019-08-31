package Queue;

public class UnOrderedPriorityQueue {

	private PriorityNode head;
	
	private PriorityNode tail;
	
	private PriorityNode min;
	
	private int size = 0;
	
	public void addNode(int value,int priority) {
		
		PriorityNode node = new PriorityNode(value,priority);
		if(head == null) {
			this.head = node;
			this.tail = node;
			this.min = node;
		}else {
			node.setNext(head);
			head = node;
			if(node.getPriority() < this.min.getPriority()) {
				this.min = node;
			}
		}
		this.size++;
	}

	public int getMin() {
		if(isEmpty()) {
			return -1;
		}
		return this.min.getValue();
	}
	
	public int deleteMin() {
		
		if(isEmpty()) {
			return -1;
		}
		
		int value = this.min.getValue();
		
		PriorityNode iter = this.head;
		
		if(this.size == 1) {
			this.head = null;
			this.tail = null;
			this.min = null;
		}else if(this.size == 2) {
			if(this.head.getPriority() > this.head.getNext().getPriority()) {
				value = this.head.getNext().getValue();
				this.head.setNext(null);
				this.min = this.head;
			}else {
				value = this.head.getValue();
				this.head = this.head.getNext();
			    this.min = this.head;
			}
		}else {
			
			if(iter == this.min) {
				this.head = this.head.getNext();
			}else {
				while(iter.getNext() != this.min) {
					iter = iter.getNext();
				}
				if(min == tail) {
					iter.setNext(null);
					
				}				
				else {
					iter.setNext(min.getNext());
				}
			}
			
			
			PriorityNode new_iter = this.head;
			PriorityNode new_min = this.head;
			
			while(new_iter != null) {
				
				if(new_iter.getPriority() < new_min.getPriority()) {
					new_min = new_iter;
				}
				new_iter = new_iter.getNext();
				
			}
			this.min = new_min;	
		}
		this.size--;
		return value;
	}
	
	public boolean isEmpty() {
		return this.size == 0;
	}
	
	public void traverse() {
		PriorityNode iter = this.head;
		while(iter != null) {
			System.out.println("Value: "+iter.getValue() + " - Priority: " + iter.getPriority());
			iter = iter.getNext();
		}	
	}

	
}
