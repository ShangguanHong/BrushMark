package main

func moveZeroes(nums []int) {
	for left, right := 0, 0; right < len(nums); right++ {
		if nums[right] != 0 {
			nums[left], nums[right] = nums[right], nums[left]
			left++
		}
	}
}
