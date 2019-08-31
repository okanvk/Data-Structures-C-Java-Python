package Arrays;

public class TwoDimensionArray {
	
	private int[][] arr = null;
	
	public TwoDimensionArray(int rows,int cols) {
		this.arr = new int[rows][cols];
		for(int i = 0; i<this.arr.length;i++) {
			for(int j = 0; j<this.arr[i].length;j++) {
				this.arr[i][j] = Integer.MIN_VALUE;
			}
		}
	}
	
	public void traverseArray() {
		for(int i = 0;i<this.arr.length;i++) {
			for(int j = 0;j<this.arr[i].length;j++) {
				System.out.print(this.arr[i][j]);
			}
			System.out.println();
		}
	}
	
	public boolean insertValueInTheArray(int row,int col,int value) {
		try {
			if(this.arr[row][col] == Integer.MIN_VALUE) {
				this.arr[row][col] = value;
				return true;
			}
			return false;
		}catch(Exception e) {
			return false;
		}
	}
	
	public int accessSingleCell(int row,int col) {
		try {
			return this.arr[row][col];
		}catch(Exception e) {
			return -1;
		}
	}
	
	public boolean searchingSingleValue(int value) {
		for(int i = 0;i<this.arr.length;i++) {
			for(int j = 0;j<this.arr[i].length;j++) {
				if(this.arr[i][j] == value) {
					return true;
				}
			}
		}
		return false;
	}
	
	public boolean deleteFromGivenCell(int row,int col) {
		
		try {
			this.arr[row][col] = Integer.MIN_VALUE;
			return true;
		}catch(Exception e) {
			return false;
		}
		
	}
	

}
