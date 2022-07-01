package main

import (
	"sort"
)

// 给你一个整数数组 nums ，你可以对它进行一些操作。
//
// 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。
//
// 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
//
//
//
// 示例 1：
//
// 输入：nums = [3,4,2]
// 输出：6
// 解释：
// 删除 4 获得 4 个点数，因此 3 也被删除。
// 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
// 示例 2：
//
// 输入：nums = [2,2,3,3,3,4]
// 输出：9
// 解释：
// 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
// 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
// 总共获得 9 个点数。
//
//
// 提示：
//
// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 104

func deleteAndEarn(nums []int) int {
	record := make(map[int]int)
	for _, num := range nums {
		record[num] += num
	}

	nums = make([]int, 0, len(record))
	for k := range record {
		nums = append(nums, k)
	}

	sort.Ints(nums)

	n := len(nums)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		dp[i][i] = record[nums[i]]
	}

	max := func(x, y int) int {
		if x > y {
			return x
		}

		return y
	}

	for i := n - 2; i >= 0; i-- {
		for j := n + 1; j < n; j++ {
			for k := i; k < j; k++ {

			}
		}
	}

}
