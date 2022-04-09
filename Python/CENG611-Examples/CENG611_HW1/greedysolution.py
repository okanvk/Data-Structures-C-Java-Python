def greedy_func_to_maximize_score(grid):
  total = 0
  (nDown, nRight) = (0,0)
  max_row_or_column_n  = len(grid) -1


  total += grid[nDown][nRight] 
  while nDown != max_row_or_column_n or nRight != max_row_or_column_n:
      
      if nRight == max_row_or_column_n:
        nDown += 1
      elif nDown == max_row_or_column_n:
        nRight += 1
      elif grid[nDown+1][nRight] > grid[nDown][nRight+1]:
              nDown+= 1                 
      else:
              nRight += 1   
      total += grid[nDown][nRight] 
  return total,nDown,nRight

grid = [

       [62,74,83,56],
       [49,86,59,70],
       [54,46,73,92],
       [1000,97,26,28] 

       ]
print(greedy_func_to_maximize_score(grid))