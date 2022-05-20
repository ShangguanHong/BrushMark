package LeetCode

func updateMatrix(mat [][]int) [][]int {
	n := len(mat)
	m := len(mat[0])
	res := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, m)
	}

	min := func(a, b int) int {
		if a < b {
			return a
		}

		return b
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == 0 {
				res[i][j] = 0
			} else {
				res[i][j] = 10001
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if i-1 >= 0 {
				res[i][j] = min(res[i][j], res[i-1][j]+1)
			}

			if j-1 >= 0 {
				res[i][j] = min(res[i][j], res[i][j-1]+1)
			}
		}
	}

	for i := n - 1; i >= 0; i-- {
		for j := m - 1; j >= 0; j-- {
			if i+1 < n {
				res[i][j] = min(res[i][j], res[i+1][j]+1)
			}

			if j+1 < m {
				res[i][j] = min(res[i][j], res[i][j+1]+1)
			}
		}
	}
	return res
}
