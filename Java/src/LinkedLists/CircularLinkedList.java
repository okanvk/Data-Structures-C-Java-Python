package LinkedLists;

public class CircularLinkedList {

	private SingularNode head;
	
	private SingularNode tail;
	
	private int size = 0;
	
	public CircularLinkedList() {
		this.head = null;
		this.tail = null;
		
	}
	
	public void traverse() {
		
		if(head == null)
			return;
		int curr_size = this.size;
		SingularNode iter = head;
		while(curr_size != 0 ) {
			curr_size--;
			System.out.println(iter.getValue());
			iter = iter.getNext();
		}	
	}
	
	public void addFront(int value) {
		
		SingularNode node = new SingularNode(value);
		
		if(!initiation(node)){
			node.setNext(head);
			head = node;
			tail.setNext(head);
		}
		this.size += 1;
	}
	
	public void addRear(int value) {
		SingularNode node = new SingularNode(value);
		
		if(!initiation(node)){
			node.setNext(head);
			tail.setNext(node);
			tail = node;
			
		}
		this.size += 1;
	}
	
	public void addNthNode(int value,int n) {
		if(n > this.size || n < 2)
			return;
		
		if(n == this.size) {
			addRear(value);
			return;
		}

		int start = 2;
		SingularNode iter = this.head;
		while(start != n) {
			start += 1;
			iter = iter.getNext();
		}

		SingularNode node = new SingularNode(value);
		SingularNode iterNext = iter.getNext();
		
		node.setNext(iterNext);
		iter.setNext(node);
		
	}
	
	public void deleteNodeFromNthNode(int n) {
		
		if(n > this.size || n < 1)
			return;
		
		if(n == 1) {
			this.deleteNodeFromFront();
			return;
		}
		
		SingularNode iter = this.head;
		int curr = 1;
		
		while( curr != (n-1)) {
			curr ++;
			iter = iter.getNext();	
		}
		
		SingularNode will_deleted = iter.getNext();
		SingularNode link = will_deleted.getNext();
		if(link == null) {
			tail = iter;
		}
		else
			iter.setNext(link);
		this.size--;
	}
	
	public void deleteNodeFromFront() {
		
		if(this.size == 0)
			return;
		else if(this.size == 1) {
			this.head = null;
			this.tail = null;
		}else {
			this.head = this.head.getNext();
			this.tail.setNext(head);	
		}
		this.size--;
	}
	
	public void deleteNodeFromRear() {
		
		if(this.size == 0)
			return;
		else if(this.size == 1) {
			this.head = null;
			this.tail = null;
		}else if(this.size == 2) {
			this.head.setNext(this.head);
			this.tail = this.head;
		}	
		else {
			SingularNode iter = this.head;
			while(iter.getNext().getNext() != tail) {
				iter = iter.getNext();
			}
			SingularNode new_tail = iter.getNext();
			new_tail.setNext(this.head);
			tail = new_tail;	
		}
		this.size--;
	}
	
	
	
	public boolean searchValue(int value) {
		
		SingularNode iter = this.head;	
		int curr_size = this.size;
		while(curr_size != 0) {
			if(iter.getValue() == value)
				return true;
			else {
				iter = iter.getNext();
			}
			curr_size--;
		}
		return false;
	}
	
	private boolean initiation(SingularNode node) {
		
		if(head == null && tail == null) {
			
			this.head = node;
			this.tail = node;	
			node.setNext(node);
			return true;
		}
		return false;
	}

}
