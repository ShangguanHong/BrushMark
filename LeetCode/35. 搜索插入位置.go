package main

func searchInsert(nums []int, target int) int {
	if nums[0] > target {
		return 0
	}

	if nums[len(nums)-1] < target {
		return len(nums)
	}

	var (
		left, right = 0, len(nums) - 1
		mid         = 0
	)

	for left <= right {
		mid = left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] >= target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return left
}
