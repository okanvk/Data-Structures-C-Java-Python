package Tree;

import java.util.LinkedList;
import java.util.Queue;


public class BinaryTreeMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		BinaryTree bt = new BinaryTree();

		
		levelOrder(bt.getRoot());
		
		insertValue(bt.getRoot(),355);
		
		System.out.println("-");
		
		deleteNode(bt.getRoot(),3);
		
		deleteNode(bt.getRoot(),5555);
		
		levelOrder(bt.getRoot());
		
		
	}
	
	public static void deleteNode(Node node,int value) {
		
		Queue<Node> queue = new LinkedList();
		
		queue.add(node);
		
		Node willDeleted = null;
		Node deepestNode = null;
		
		while(!queue.isEmpty()) {
			
			Node n = queue.remove();
			
			if(n.getData() == value) {
				willDeleted = n;
			}
			
			if(n.getLeft() != null)
				queue.add(n.getLeft());
			
			if(n.getRight() != null)
				queue.add(n.getRight());
			
			if(queue.size() == 0) {
				deepestNode = n;
			}
		}

		if(willDeleted != null && deepestNode != null) {	
			
			queue.add(node);

			while(!queue.isEmpty()) {
				Node n = queue.remove();
				
				if(n.getLeft() != null)
					queue.add(n.getLeft());
				
				if(n.getRight() != null)
					queue.add(n.getRight());
				
				if(n.getRight() == deepestNode) {
					willDeleted.setData(deepestNode.getData());
					n.setRight(null);
					break;
				}
				if(n.getLeft() == deepestNode) {
					willDeleted.setData(deepestNode.getData());
					n.setLeft(null);
					break;
				}

			}
				
		}
	}
	
	public static void insertValue(Node node,int value) {
		
		Queue<Node> queue = new LinkedList();
		
		queue.add(node);
		
		while(!queue.isEmpty()) {
			
			Node n = queue.remove();
			
			if(n.getLeft() != null)
				queue.add(n.getLeft());
			else {
				n.setLeft(new Node(value));
				return;
			}
			if(n.getRight() != null)
				queue.add(n.getRight());
			else {
				n.setRight(new Node(value));
				return;
			}
			
		}
	}
	
	public static boolean searchValue(Node node,int value) {
		
		Queue<Node> queue = new LinkedList();
		
		queue.add(node);
		
		while(!queue.isEmpty()) {
			
			Node n = queue.remove();
			
			if(n.getData() == value) {
				return true;
			}
			
			if(n.getLeft() != null)
				queue.add(n.getLeft());
			
			if(n.getRight() != null)
				queue.add(n.getRight());
			
			
		}
		return false;
	}
	
	public static void preOrder(Node node) {
		if(node != null) {
			System.out.println(node.getData());
			preOrder(node.getLeft());
			preOrder(node.getRight());
		}
	}
	
	public static void inOrder(Node node) {
		if(node != null) {
			inOrder(node.getLeft());
			System.out.println(node.getData());
			inOrder(node.getRight());
		}
	}
	
	public static void postOrder(Node node) {
		if(node != null) {
			postOrder(node.getLeft());
			postOrder(node.getRight());
			System.out.println(node.getData());
		}
	}
	
	public static void levelOrder(Node node) {
		
		Queue<Node> queue = new LinkedList<>(); 
		
		queue.add(node);
		
		while(!queue.isEmpty()) {
			
			Node n = queue.remove();
			
			System.out.println(n.getData());
			
			if(n.getLeft() != null)
				queue.add(n.getLeft());
			
			if(n.getRight() != null)
				queue.add(n.getRight());

		}
	}
	

}
