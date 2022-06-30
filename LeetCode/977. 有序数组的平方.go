package main

func sortedSquares(nums []int) []int {
	var (
		n           = len(nums) - 1
		left, right = 0, n
		res         = make([]int, n+1)
	)

	for left <= right {
		num1 := nums[left] * nums[left]
		num2 := nums[right] * nums[right]
		if num1 > num2 {
			res[n] = num1
			left++
		} else {
			res[n] = num2
			right--
		}
		n--
	}

	return res
}
