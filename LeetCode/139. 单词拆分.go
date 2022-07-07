package main

import (
	"fmt"
)

// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//
//
//
// 示例 1：
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 示例 2：
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//      注意，你可以重复使用字典中的单词。
// 示例 3：
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false
//
//
// 提示：
//
// 1 <= s.length <= 300
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 20
// s 和 wordDict[i] 仅有小写英文字母组成
// wordDict 中的所有字符串 互不相同
//
// 来源：力扣（LeetCode）
// 链接：[https://leetcode.cn/problems/word-break](https://leetcode.cn/problems/word-break)
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func wordBreak(s string, wordDict []string) bool {
	n, m := len(s), len(wordDict)
	dp := make([][]bool, n+1)
	for i := range dp {
		dp[i] = make([]bool, m+1)
	}

	for i := 0; i <= m; i++ {
		dp[0][i] = true
	}

	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			dp[i][j] = dp[i][j-1]

			for k := 1; k <= j; k++ {
				if dp[i][j] {
					break
				}

				l := len(wordDict[k-1])
				if i-l >= 0 {
					dp[i][j] = dp[i-l][j] && s[i-l:i] == wordDict[k-1]
				}
			}
		}
	}

	return dp[n][m]
}

func main() {
	fmt.Println(wordBreak("leetcode", []string{"leet", "code"}))
	fmt.Println(wordBreak("applepenapple", []string{"apple", "pen"}))
	fmt.Println(wordBreak("catsandog", []string{"cats", "dog", "sand", "and", "cat"}))
}
