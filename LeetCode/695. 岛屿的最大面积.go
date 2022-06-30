package main

func maxAreaOfIsland(grid [][]int) int {
	m := len(grid)
	n := len(grid[0])
	res := 0

	visit := make([][]bool, m)
	for i := range visit {
		visit[i] = make([]bool, n)
	}

	for x := 0; x < m; x++ {
		for y := 0; y < n; y++ {
			if grid[x][y] == 0 || visit[x][y] {
				continue
			}
			area := 0
			maxAreaOfIslandBfs(grid, x, y, m, n, visit, &area)
			if res < area {
				res = area
			}
		}
	}
	return res
}

func maxAreaOfIslandBfs(grid [][]int, x, y, m, n int, visit [][]bool, area *int) {
	if x < 0 || y < 0 || x >= m || y >= n || visit[x][y] || grid[x][y] == 0 {
		return
	}

	*area++
	visit[x][y] = true
	maxAreaOfIslandBfs(grid, x+1, y, m, n, visit, area)
	maxAreaOfIslandBfs(grid, x, y+1, m, n, visit, area)
	maxAreaOfIslandBfs(grid, x-1, y, m, n, visit, area)
	maxAreaOfIslandBfs(grid, x, y-1, m, n, visit, area)
}
