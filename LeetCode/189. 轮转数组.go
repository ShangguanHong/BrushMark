package main

func rotate(nums []int, k int) {
	k %= len(nums)
	reverse := func(nums []int) {
		for i := 0; i < len(nums)/2; i++ {
			nums[i], nums[len(nums)-i-1] = nums[len(nums)-i-1], nums[i]
		}
	}

	reverse(nums)
	reverse(nums[:k])
	reverse(nums[k:])

	return
}
