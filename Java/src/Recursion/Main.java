package Recursion;

public class Main {

	public static void main(String[] args) {
		
		System.out.println(findFibonacci(5));
		
		int[] array = {5,12,16,20,17,3,5,35,63,25,38};
		int length = array.length;
		System.out.println(findBiggestNumber(array,0,length));
		
		
	}
	
	public static int findBiggestNumber(int[] array,int start,int length) {
		
		int max = array[start];
		if(start+1 == length) {
			return array[start];
		}
		else {
			int value =findBiggestNumber(array,start+1,length);
			if(value > max) {
				max = value;
			}
		}
		return max;
		
	}
	
	public static int findFibonacci(int number) {
		
		if(number == 1 || number == 2) {
			return number-1;
		}
		return findFibonacci(number-1) + findFibonacci(number-2);
	}

}
