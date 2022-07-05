package main

import (
	"fmt"
)

// 给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。
//
// 环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。
//
// 子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。
//
//
//
// 示例 1：
//
// 输入：nums = [1,-2,3,-2]
// 输出：3
// 解释：从子数组 [3] 得到最大和 3
// 示例 2：
//
// 输入：nums = [5,-3,5]
// 输出：10
// 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
// 示例 3：
//
// 输入：nums = [3,-2,2,-3]
// 输出：3
// 解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
//
//
// 提示：
//
// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104​​​​​​​
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/maximum-sum-circular-subarray
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func maxSubarraySumCircular(nums []int) int {
	n := len(nums)
	if n <= 1 {
		return nums[0]
	}

	maxFunc := func(x, y int) int {
		if x > y {
			return x
		}

		return y
	}

	minFunc := func(x, y int) int {
		if x > y {
			return y
		}

		return x
	}

	curMax, max, curMin, min, sum := nums[0], nums[0], nums[0], nums[0], nums[0]
	for i := 1; i < n; i++ {
		sum += nums[i]
		curMax = maxFunc(curMax+nums[i], nums[i])
		curMin = minFunc(curMin+nums[i], nums[i])
		max = maxFunc(max, curMax)
		min = minFunc(min, curMin)
	}

	if max < 0 {
		return max
	}

	return maxFunc(max, sum-min)
}

func main() {
	fmt.Println(maxSubarraySumCircular([]int{1, -2, 3, -2}))
	fmt.Println(maxSubarraySumCircular([]int{5, -3, 5}))
	fmt.Println(maxSubarraySumCircular([]int{3, -2, 2, -3}))
}
