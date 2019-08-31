package LinkedLists;

public class SingularLinkedList {
	
	
	private SingularNode head;
	
	private SingularNode tail;
	
	private int size = 0;
	
	public SingularLinkedList() {
		this.head = null;
		this.tail = null;
		
	}
	
	public void traverse() {
		
		SingularNode iter = head;
		while(iter != null) {
			System.out.println(iter.getValue());
			iter = iter.getNext();
		}
		
		
	}
	
	public void addFront(int value) {
		
		SingularNode node = new SingularNode(value);
		
		if(!initiation(node)){
			node.setNext(head);
			head = node;
		}
		this.size += 1;
	}
	
	public void addRear(int value) {
		SingularNode node = new SingularNode(value);
		
		if(!initiation(node)){
			tail.setNext(node);
			tail = node;
		}
		this.size += 1;
	}
	
	public void addNthNode(int value,int n) {
		if(n > this.size || n < 2)
			return;

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
	
	public boolean searchValue(int value) {
		
		SingularNode iter = this.head;	
		while(iter != null) {
			if(iter.getValue() == value)
				return true;
			else {
				iter = iter.getNext();
			}
		}
		return false;
	}
	
	public void deleteNodeFromFront() {
		
		
		if(this.size == 0)
			return;
		else if(this.size == 1) {
			this.head = null;
			this.tail = null;			
		}else {
			this.head = this.head.getNext();
		}	
		this.size--;
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

	public void deleteNodeFromRear() {
		
		if(this.size == 0)
			return;
		else if(this.size == 1) {
			this.head = null;
			this.tail = null;
		}else if(this.size == 2) {
			this.head.setNext(null);
			this.tail = this.head;
		}	
		else {
			SingularNode iter = this.head;
			while(iter.getNext().getNext() != tail) {
				iter = iter.getNext();
			}
			SingularNode new_tail = iter.getNext();
			new_tail.setNext(null);
			tail = new_tail;	
		}
		this.size--;
	}
	

	private boolean initiation(SingularNode node) {
	
		if(head == null && tail == null) {
			
			this.head = node;
			this.tail = node;	
			return true;
		}
		return false;
	}
	

}
