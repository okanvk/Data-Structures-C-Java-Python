package Queue;



public class OrderedPriorityQueue {
	
	private PriorityNode head;
	
	private PriorityNode tail;
	
	private int size = 0;
	
	public void addNode(int value,int priority) {
		
		PriorityNode node = new PriorityNode(value,priority);
		
		if(head == null) {
			this.head = node;
			this.tail = node;
		}
		else if(tail.getPriority() <= node.getPriority()) {
			this.tail.setNext(node);
			this.tail = node;
		}
		else if(head.getPriority() >= node.getPriority()) {
			node.setNext(this.head);
			this.head = node;
		}else {
			
			PriorityNode iter = this.head;
			while(iter.getNext().getPriority() < node.getPriority()) {
				iter = iter.getNext();
			}
			PriorityNode lessValuablePriorityNode = iter.getNext();
			iter.setNext(node);
			node.setNext(lessValuablePriorityNode);
		}
		this.size++;
		
	}

	public int getMin() {
		if(isEmpty()) {
			return -1;
		}
		return this.head.getValue();
	}
	
	public int deleteMin() {
		
		if(isEmpty()) {
			return -1;
		}
		int value = this.head.getValue();
		this.head = this.head.getNext();
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
