package Arrays;

public class Array2DMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		TwoDimensionArray arr1 = new TwoDimensionArray(3,5);
		
		arr1.traverseArray();
		
		System.out.println(arr1.insertValueInTheArray(2, 3, 100));
		arr1.traverseArray();
		System.out.println(arr1.insertValueInTheArray(2, 3, 100));
		System.out.println(arr1.insertValueInTheArray(2, 4, 12));
		System.out.println(arr1.accessSingleCell(2, 3));
		System.out.println(arr1.accessSingleCell(2, 6));
		
		System.out.println(arr1.searchingSingleValue(12));
		System.out.println(arr1.searchingSingleValue(102));
		
		System.out.println("---");
		
		System.out.println(arr1.deleteFromGivenCell(3, 3));
		System.out.println(arr1.deleteFromGivenCell(2, 3));
		System.out.println(arr1.deleteFromGivenCell(10,10));
	
	}

}
