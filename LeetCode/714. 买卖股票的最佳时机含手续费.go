package main

import (
	"fmt"
)

// 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
//
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
//
// 返回获得利润的最大值。
//
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
//
//
// 示例 1：
//
// 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
// 输出：8
// 解释：能够达到的最大利润:
// 在此处买入prices[0] = 1
// 在此处卖出 prices[3] = 8
// 在此处买入 prices[4] = 4
// 在此处卖出 prices[5] = 9
// 总利润:((8 - 1) - 2) + ((9 - 4) - 2) = 8
// 示例 2：
//
// 输入：prices = [1,3,7,5,10,3], fee = 3
// 输出：6
//
// 提示：
//
// 1 <= prices.length <= 5 * 10^4
// 1 <= prices[i] < 5 * 10^4
// 0 <= fee < 5 * 10^4
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func maxProfit3(prices []int, fee int) int {
	n := len(prices)
	dp := make([][]int, 2)
	dp[0] = make([]int, n)
	dp[1] = make([]int, n)

	dp[0][0] = -prices[0]
	dp[1][0] = 0

	max := func(x, y int) int {
		if x > y {
			return x
		}

		return y
	}

	for i := 1; i < n; i++ {
		dp[0][i] = max(dp[0][i-1], dp[1][i-1]-prices[i])
		dp[1][i] = max(dp[1][i-1], dp[0][i-1]+prices[i]-fee)
	}

	return dp[1][n-1]
}

func main() {
	fmt.Println(maxProfit3([]int{1, 3, 2, 8, 4, 9}, 2))
	fmt.Println(maxProfit3([]int{1, 3, 7, 5, 10, 3}, 3))
	fmt.Println(maxProfit3([]int{9, 8, 7, 1, 2}, 3))
}
