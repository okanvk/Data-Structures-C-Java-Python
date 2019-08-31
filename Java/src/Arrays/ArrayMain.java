package Arrays;

public class ArrayMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		OneDimensionArray arr1 = new OneDimensionArray(10);
		
		arr1.traverse();
		
		System.out.println();
		
		System.out.println(arr1.insert(0, 100));
		System.out.println(arr1.insert(1, 10));
		System.out.println(arr1.insert(2, 1));
		System.out.println(arr1.insert(2, 100));
		System.out.println(arr1.insert(12, 100));
		
		System.out.println(arr1.searchInArray(10));
		System.out.println(arr1.searchInArray(20));
	}
	
	

}
