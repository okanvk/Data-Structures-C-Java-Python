def dynamic_func_to_maximize_score(grid):
 

    N = len(grid)
 
    sum = [[0 for i in range(N + 1)]
              for i in range(N + 1)]
    n_left, n_right = 0, 0
    for i in range(1, N + 1):
        for j in range(1, N + 1):
             sum[i][j] = max(sum[i - 1][j],sum[i][j - 1]) +grid[i - 1][j - 1]
 
        n_left += 1
        n_right += 1
    total_score = sum[n_left][n_right]
    n_left -= 1
    n_right -= 1
    return total_score,n_left,n_right

grid = [
  [89,99,41,64,2,70,71],
  [38,52,32,11,40,75,83],
  [13,87,38,27,35,9,33],
  [73,65,6,7,17,76,36],
  [65,34,22,90,98,40,60],
  [98,80,53,36,12,71,72],
  [36,18,25,78,21,18,60],           
          ]


print(dynamic_func_to_maximize_score(grid))