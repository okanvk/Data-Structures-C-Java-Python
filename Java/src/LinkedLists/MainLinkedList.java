package LinkedLists;

public class MainLinkedList {

	public static void main(String[] args) {
		
		DoubleLinkedList linkedList = new DoubleLinkedList();
		
		linkedList.addFront(1);
		linkedList.addFront(2);
		linkedList.addFront(20);
		linkedList.addRear(12);

		
		
		linkedList.frontTraverse();

		System.out.println("---");


		linkedList.frontTraverse();
		


	}

}
