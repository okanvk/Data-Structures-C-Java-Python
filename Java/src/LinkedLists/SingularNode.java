package LinkedLists;

public class SingularNode {
	
	private int value;
	private SingularNode next;
	
	public SingularNode(int value) {
		this.value = value;
		this.next = null;
	}
	
	public int getValue() {
		return value;
	}
	public void setValue(int value) {
		this.value = value;
	}
	public SingularNode getNext() {
		return next;
	}
	public void setNext(SingularNode next) {
		this.next = next;
	}
}
