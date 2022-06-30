package main

import (
	"strings"
)

func reverseWords(s string) string {
	var (
		l, r = 0, 0
		ss   strings.Builder
	)

	f := func() {
		for i := r - 1; i >= l; i-- {
			ss.WriteByte(s[i])
		}
	}

	for r < len(s) {
		if s[r] == ' ' {
			f()
			ss.WriteByte(' ')
			l = r + 1
		}
		r++
	}

	if l != r {
		f()
	}

	return ss.String()
}
