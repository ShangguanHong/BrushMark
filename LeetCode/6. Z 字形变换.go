package main

import (
	"strings"
)

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	var (
		l     = len(s)
		res   = strings.Builder{}
		batch = 2*numRows - 2
	)

	for i := 0; i < numRows; i++ {
		if i == 0 || i == numRows-1 {
			for idx := i; idx < l; idx = idx + batch {
				res.WriteByte(s[idx])
			}
		} else {
			idx := i
			offset := 2 * (numRows - i - 1)
			odd := true
			for idx < l {
				res.WriteByte(s[idx])
				if odd {
					idx += offset
				} else {
					idx = idx + batch - offset
				}
				odd = !odd
			}
		}
	}

	return res.String()
}
