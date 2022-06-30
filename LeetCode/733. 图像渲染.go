package main

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	m := len(image)
	n := len(image[0])

	visit := make([][]bool, m)
	for i := range visit {
		visit[i] = make([]bool, n)
	}

	originColor := image[sr][sc]

	floodFillFill(image, sr, sc, newColor, visit, m, n, originColor)

	return image
}

func floodFillFill(image [][]int, x int, y int, newColor int, visit [][]bool, m int, n int, originColor int) {
	if x < 0 || y < 0 || x >= m || y >= n || visit[x][y] || image[x][y] != originColor {
		return
	}

	image[x][y] = newColor
	visit[x][y] = true

	floodFillFill(image, x+1, y, newColor, visit, m, n, originColor)
	floodFillFill(image, x, y+1, newColor, visit, m, n, originColor)
	floodFillFill(image, x-1, y, newColor, visit, m, n, originColor)
	floodFillFill(image, x, y-1, newColor, visit, m, n, originColor)
}
