package LeetCode

func lengthOfLongestSubstring(s string) int {
	var (
		res    = 0
		l, r   = 0, 0
		record = map[byte]int{}
	)

	max := func(a, b int) int {
		if a > b {
			return a
		}

		return b
	}

	for ; r < len(s); r++ {
		if i, ok := record[s[r]]; ok && i >= l {
			res = max(res, r-l)
			l = i + 1
		} else if r == len(s)-1 {
			res = max(res, r-l+1)
		}

		record[s[r]] = r
	}

	return res
}
