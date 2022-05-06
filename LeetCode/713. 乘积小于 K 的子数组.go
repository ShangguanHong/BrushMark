package LeetCode

func numSubarrayProductLessThanK(nums []int, k int) int {
	if len(nums) == 1 {
		if nums[0] < k {
			return 1
		} else {
			return 0
		}
	}

	sum := func(a, b int) int {
		n := b - a
		return (n*n + n) / 2
	}

	var (
		res         = 0
		left, right = 0, 0
		product     = 1
	)

	for ; right < len(nums); right++ {
		product *= nums[right]
		if product < k {
			continue
		}

		res += sum(left, right)

		for left <= right {
			product /= nums[left]
			left++
			if product >= k {
				continue
			}
			res -= sum(left, right)
			break
		}
	}

	res += sum(left, right)

	return res
}
