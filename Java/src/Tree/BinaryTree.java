package Tree;

public class BinaryTree {
	
	private Node root;
	
	public BinaryTree() {
		this.root = null;
		this.prepTree();	
	}
	
	public Node getRoot() {
		return this.root;
	}
	
	private void prepTree() {
		
		Node node1 = new Node(20);
		this.root = node1;
		
		Node node2 = new Node(100);
		Node node3 = new Node(3);
		
		this.root.setLeft(node2);
		this.root.setRight(node3);
		
		Node node4 = new Node(50);
		Node node5 = new Node(15);
		Node node6 = new Node(250);
		Node node7 = new Node(35);
		
		node2.setLeft(node4);
		node2.setRight(node5);
		
		node3.setLeft(node6);
		node3.setRight(node7);
		
		Node node8 = new Node(222);
		node4.setLeft(node8);
	}

}
