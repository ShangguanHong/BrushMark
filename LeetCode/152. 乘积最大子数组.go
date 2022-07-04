package main

import (
	"fmt"
)

// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//
// 测试用例的答案是一个 32-位 整数。
//
// 子数组 是数组的连续子序列。
//
//
//
// 示例 1:
//
// 输入: nums = [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:
//
// 输入: nums = [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
//
//
// 提示:
//
// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/maximum-product-subarray
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
func maxProduct(nums []int) int {
	n := len(nums)
	if n <= 1 {
		return nums[0]
	}

	curMax, curMin, ans := nums[0], nums[0], nums[0]
	min := func(x, y int) int {
		if x < y {
			return x
		}

		return y
	}
	max := func(x, y int) int {
		if x < y {
			return y
		}

		return x
	}

	for i := 1; i < n; i++ {
		if nums[i] < 0 {
			curMax, curMin = curMin, curMax
		}
		curMax = max(curMax*nums[i], nums[i])
		curMin = min(curMin*nums[i], nums[i])
		ans = max(ans, curMax)
	}

	return ans
}

func main() {
	fmt.Println(maxProduct([]int{2, 3, -2, 4}))
	fmt.Println(maxProduct([]int{-2, 0, -1}))
}
