package main

func maxArea(height []int) int {
	var (
		res         int
		left, right = 0, len(height) - 1
	)

	for left < right {
		curArea := min(height[left], height[right]) * (right - left)
		res = max(res, curArea)
		if height[left] < height[right] {
			left++
		} else {
			right--
		}
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}

	return b
}

func max(a, b int) int {
	if a < b {
		return b
	}

	return a
}
