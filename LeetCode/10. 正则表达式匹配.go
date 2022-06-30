package main

import (
	"fmt"
	"strconv"
)

func isMatch(s string, p string) bool {
	if p == ".*" {
		return true
	}

	record := make(map[string]bool, len(s)*len(p))

	return dp(s, p, 0, 0, record)
}

func dp(s, p string, i, j int, record map[string]bool) bool {
	key := strconv.Itoa(i) + "," + strconv.Itoa(j)
	if v, ok := record[key]; ok {
		return v
	}

	if j == len(p) {
		record[key] = i == len(s)
		return record[key]
	}

	if i == len(s) {
		if (len(p)-j)&1 == 1 {
			record[key] = false
			return record[key]
		}

		for ; j < len(p); j += 2 {
			if p[j+1] != '*' {
				record[key] = false
				return record[key]
			}
		}

		record[key] = true
		return record[key]
	}

	if s[i] == p[j] || p[j] == '.' {
		if j < len(p)-1 && p[j+1] == '*' {
			record[key] = dp(s, p, i+1, j, record) || dp(s, p, i, j+2, record)
		} else {
			record[key] = dp(s, p, i+1, j+1, record)
		}
	} else if j < len(p)-1 && p[j+1] == '*' {
		record[key] = dp(s, p, i, j+2, record)
	} else {
		record[key] = false
	}

	return record[key]
}

func main() {
	fmt.Println(isMatch("ab", ".*c"))
}
