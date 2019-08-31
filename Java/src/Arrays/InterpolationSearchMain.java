package Arrays;

public class InterpolationSearchMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = { 15,100,220,353,546};
		
		System.out.println(interpolation_search(arr,220));
		

	}
	
	public static int interpolation_search(int[] arr,int value) {
		
		int first = 0;
		int end = arr.length-1;
		
		while(first < end && arr[first] <= value && arr[end] >= value) {
			
			if(first == end) {
				if(arr[first] == value) {
					return first;
				}
				else {
					return -1;
				}
			}
			
			 int pos = first + (((end-first) / (arr[end]-arr[first]))*(value - arr[first])); 
			
			 if(arr[pos] == value) {
				 return pos;
			 }
			 
			 if(arr[pos] < value) {
				 first = pos + 1;
			 }else{
				 end = pos - 1;
			 }	
		}
		return -1;
	}

}
