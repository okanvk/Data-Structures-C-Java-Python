package Tree;

public class BinaryHeapMain {

	 public static void main(String[] arg) 
	 { 
	     System.out.println("The Min Heap is "); 
	     BinaryHeap minHeap = new BinaryHeap(15); 
	     minHeap.insert(5); 
	     minHeap.insert(3); 
	     minHeap.insert(17); 
	     minHeap.insert(10); 
	     minHeap.insert(84); 
	     minHeap.insert(19); 
	     minHeap.insert(6); 
	     minHeap.insert(22); 
	     minHeap.insert(9); 
	     minHeap.minHeap(); 

	     minHeap.print(); 
	     System.out.println("The Min val is " + minHeap.remove()); 
	     System.out.println("The Min val is " + minHeap.remove()); 

	 } 

}
