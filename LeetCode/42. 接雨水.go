package main

import (
	"fmt"
)

// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
// 示例 1：
//
// 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
// 输出：6
// 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
// 示例 2：
//
// 输入：height = [4,2,0,3,2,5]
// 输出：9
//
//
// 提示：
//
// n == height.length
// 1 <= n <= 2 * 104
// 0 <= height[i] <= 105
//
// 来源：力扣（LeetCode）
// 链接：[https://leetcode.cn/problems/trapping-rain-water](https://leetcode.cn/problems/trapping-rain-water)
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func trap(height []int) int {
	ans := 0

	// 先去除头部为0的
	for len(height) > 0 && height[0] == 0 {
		height = height[1:]
	}
	if len(height) < 2 {
		return ans
	}

	stack := make([]int, 0)
	stack = append(stack, height[0])
	stackMax := height[0]

	for i := 1; i < len(height); i++ {
		if height[i] >= stackMax {
			for _, s := range stack {
				ans += stackMax - s
			}
			stack = stack[0:0]
			stackMax = height[i]
		} else {
			for j := len(stack) - 1; j >= 0; j-- {
				if stack[j] < height[i] {
					ans += height[i] - stack[j]
					stack[j] = height[i]
					continue
				}
				break
			}
		}
		stack = append(stack, height[i])
	}
	return ans
}

func main() {
	fmt.Println(trap([]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}))
	fmt.Println(trap([]int{4, 2, 0, 3, 2, 5}))
}
