package main

func intToRoman(num int) string {
	var (
		strs = []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
		nums = []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
		res  string
	)

	for i := 0; num != 0; i++ {
		for num >= nums[i] {
			res += strs[i]
			num -= nums[i]
		}
	}

	return res
}
