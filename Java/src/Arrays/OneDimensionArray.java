package Arrays;

public class OneDimensionArray {
	
	int[] arr = null;

	public OneDimensionArray(int sizeOfArray) {
		arr = new int[sizeOfArray];
		for(int i = 0;i<sizeOfArray;i++) {
			arr[i] = Integer.MIN_VALUE;
		}
	}
	
	public void traverse() {
		for(int i = 0;i<arr.length;i++) {
			System.out.print(this.arr[i] + " ");
		}
	}
	
	public boolean insert(int location,int value) {
		
		try {
			if(this.arr[location] == Integer.MIN_VALUE) {
				this.arr[location] = value;
				return true;
			}
		}catch(Exception e) {
			return false;
		}
		return false;
	}
	
	public int accesCell(int index) {
		try {
			return this.arr[index];
		}catch(Exception e) {
			return -1;
		}
	}
	
	public int searchInArray(int value) {
		for(int i = 0;i<this.arr.length;i++) {
			if(this.arr[i] == value) {
				return i;
			}
		}
		return -1;
	}
	
	public boolean deleteValueFromArrayList(int value) {
		for(int i = 0; i< this.arr.length; i++) {
			if(this.arr[i] == value) {
				this.arr[i] = Integer.MIN_VALUE;
				return true;
			}
			
		}
		return false;
	}
	
	public boolean deleteCellValue(int index) {
		try {
			this.arr[index] = Integer.MAX_VALUE;
			return true;
		}catch(Exception e) {
			return false;
		}
	}
	
}
