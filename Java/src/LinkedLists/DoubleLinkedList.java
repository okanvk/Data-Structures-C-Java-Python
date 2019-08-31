package LinkedLists;

public class DoubleLinkedList {
	
	private DoubleNode head;
	
	private DoubleNode tail;
	
	private int size = 0;
	
	public DoubleLinkedList() {
		this.head = null;
		this.tail = null;	
	}
	
	public void addFront(int value) {
		
		DoubleNode node = new DoubleNode(value);
		if(head == null) {
			this.head = node;	
			this.tail = node;
					
		}else {			
			node.setNext(head);
			head.setPrev(node);
			head = node;	
		}
		this.size++;	
	}
	
	public void addRear(int value) {
			
		DoubleNode node = new DoubleNode(value);
		if(tail == null) {
			this.head = node;	
			this.tail = node;
					
		}else {			
			node.setPrev(tail);
			tail.setNext(node);
			tail = node;	
		}
		this.size++;	
	}
	
	public void addNthNode(int value,int n) {
		if(n > this.size || n < 2)
			return;

		int start = 2;
		DoubleNode iter = this.head;
		while(start != n) {
			start += 1;
			iter = iter.getNext();
		}
		DoubleNode node = new DoubleNode(value);
		DoubleNode iterNext = iter.getNext();
		
		node.setNext(iterNext);
		node.setPrev(iter);
		iterNext.setPrev(node);
		iter.setNext(node);
		this.size++;
	}
	
	public void deleteNodeFromNthNode(int n) {
		
		if(n > this.size || n < 1)
			return;
		
		if(n == 1) {
			this.deleteNodeFromFront();
			return;
		}
		
		DoubleNode iter = this.head;
		int curr = 1;
		
		while( curr != (n-1)) {
			curr ++;
			iter = iter.getNext();	
		}
		
		DoubleNode will_deleted = iter.getNext();
		DoubleNode link = will_deleted.getNext();
		
		if(will_deleted == tail) {
			iter.setNext(null);
			this.tail = iter;
			will_deleted = null;
		}else {
			iter.setNext(link);
			link.setPrev(iter);
			will_deleted=null;
		}
		this.size--;
	}
	
	public void deleteNodeFromFront() {
			
			if(this.size == 0)
				return;
			else if(this.size == 1) {
				this.head = null;
				this.tail = null;
			}else {
				DoubleNode nextHead = this.head.getNext();
				nextHead.setPrev(null);
				this.head = nextHead;
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
			this.head.setNext(null);
			this.tail = this.head;
		}	
		else {
			DoubleNode iter = this.head;
			while(iter.getNext().getNext() != tail) {
				iter = iter.getNext();
			}
			DoubleNode new_tail = iter.getNext();
			new_tail.setNext(null);
			tail = new_tail;	
		}
		this.size--;
	}
	
	public void frontTraverse() {
		DoubleNode iter = head;
		while(iter != null) {
			
			System.out.println(iter.getValue());
			iter = iter.getNext();
		}
	}
	
	public void rearTraverse() {
		DoubleNode iter = tail;
		while(iter != null) {
			
			System.out.println(iter.getValue());
			iter = iter.getPrev();
		}
	}
	
	public boolean searchValue(int value) {
		
		DoubleNode iter = this.head;	
		while(iter != null) {
			if(iter.getValue() == value)
				return true;
			else {
				iter = iter.getNext();
			}
		}
		return false;
	}
	

}
