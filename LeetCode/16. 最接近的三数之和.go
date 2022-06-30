package main

import (
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)

	var delta = math.MaxInt
	for i := 0; i < len(nums)-2; i++ {
		newTarget := target - nums[i]
		left, right := i+1, len(nums)-1
		newDelta := math.MaxInt

		for left < right {
			sum := nums[right] + nums[left]
			tempDelta := newTarget - sum
			if math.Abs(float64(tempDelta)) < math.Abs(float64(newDelta)) {
				newDelta = tempDelta
			}

			if sum < newTarget {
				left++
			} else {
				right--
			}
		}

		if math.Abs(float64(newDelta)) < math.Abs(float64(delta)) {
			delta = newDelta
		}
	}

	return target - delta
}
