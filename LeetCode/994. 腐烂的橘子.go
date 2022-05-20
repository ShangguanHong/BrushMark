package LeetCode

import (
	"math"
)

func orangesRotting(grid [][]int) int {
	n := len(grid)
	m := len(grid[0])

	time := make([][]int, n)
	for i := 0; i < n; i++ {
		time[i] = make([]int, m)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				time[i][j] = math.MaxInt32
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] != 2 {
				continue
			}

			visit := make([][]int, n)
			for i := 0; i < n; i++ {
				visit[i] = make([]int, m)
			}
			visit[i][j] = 1

			xy := []int{i - 1, j, i + 1, j, i, j - 1, i, j + 1}
			depth := 0
			for len(xy) != 0 {
				l := len(xy)
				depth++
				for z := 0; z < l; z += 2 {
					x := xy[z]
					y := xy[z+1]
					if x < 0 || x >= n || y < 0 || y >= m || visit[x][y] == 1 {
						continue
					}
					visit[x][y] = 1
					if grid[x][y] != 1 {
						continue
					}

					if time[x][y] > depth {
						time[x][y] = depth
					}
					xy = append(xy, x-1, y, x+1, y, x, y-1, x, y+1)
				}
				xy = xy[l:]
			}
		}
	}

	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] != 1 {
				continue
			}

			if time[i][j] == math.MaxInt32 {
				return -1
			}

			if res < time[i][j] {
				res = time[i][j]
			}
		}
	}

	return res
}
