package Arrays;

public class JumpSearchMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] arr = { 5,15,25,55,72,93,152,255};
		
		System.out.println(jump_search(arr,95));
		

	}
	
	public static int jump_search(int[] arr,int value) {
		
		int block_size = (int)Math.floor(Math.sqrt(arr.length));
		int index = 0;
		
		while(!(arr[index] > value)) {
			index += block_size;
		}
		
		int start = index-block_size;
		
		while(start != index+1) {
			
			if(arr[start] == value) {
				return start;
			}
			start++;
		}
			return -1;
	}

}
