package Tree;

import java.util.LinkedList;
import java.util.Queue;

public class BinarySearchTreeMain {
	
	public static void main(String[] args) {

		
		BinarySearchTree bt = new BinarySearchTree();
		
		bt.setRoot(insertBST(bt.getRoot(),100));
		bt.setRoot(insertBST(bt.getRoot(),80));
		bt.setRoot(insertBST(bt.getRoot(),200));
		bt.setRoot(insertBST(bt.getRoot(),70));
		bt.setRoot(insertBST(bt.getRoot(),90));
		bt.setRoot(insertBST(bt.getRoot(),150));
		bt.setRoot(insertBST(bt.getRoot(),300));
		bt.setRoot(insertBST(bt.getRoot(),250));
		bt.setRoot(insertBST(bt.getRoot(),400));
		bt.setRoot(insertBST(bt.getRoot(),50));
		bt.setRoot(insertBST(bt.getRoot(),40));
		bt.setRoot(insertBST(bt.getRoot(),60));
		
		inOrder(bt.getRoot());
		

		
	
		
	}
	
	public static Node searchValue(Node node,int value) {
		
		if(node != null) {
			
			if(node.getData() == value) {
				return node;
			}
			else if(node.getData() < value) {
				return searchValue(node.getRight(),value);
			}
			else {
				return searchValue(node.getLeft(),value);
			}
			
		}
		return null;
	}
	
	public static Node insertBST(Node node,int value) {
		
		if(node == null) {
			node = new Node(value); 
		}
		else if(node.getData() <= value) {
			node.setRight(insertBST(node.getRight(),value));
		}else if(node.getData() > value) {
			node.setLeft(insertBST(node.getLeft(),value));
		}
	
		return node;
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
