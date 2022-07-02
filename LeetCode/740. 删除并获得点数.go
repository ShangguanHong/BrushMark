package main

import (
	"fmt"
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
	newNums := make([]int, 1e4+1)
	for _, num := range nums {
		newNums[num] += num
	}

	if len(newNums) == 1 {
		return newNums[nums[0]]
	}

	max := func(x, y int) int {
		if x > y {
			return x
		}

		return y
	}

	dp := make([]int, 1e4+1)
	dp[0] = newNums[0]
	dp[1] = max(newNums[0], newNums[1])

	for i := 2; i <= 1e4; i++ {
		dp[i] = max(dp[i-1], dp[i-2]+newNums[i])
	}

	return dp[1e4]
}

func main() {
	fmt.Println(deleteAndEarn([]int{1, 1, 1, 2, 4, 5, 5, 5, 6}))
}
