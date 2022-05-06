package LeetCode

func search(nums []int, target int) int {
	if nums[0] > target || nums[len(nums)-1] < target {
		return -1
	}

	var (
		left, right = 0, len(nums) - 1
	)

	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	return -1
}
