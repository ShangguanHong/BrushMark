package main

/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	var (
		left, right = 0, n
		mid         = 0
		res         = 0
	)

	for left <= right {
		mid = left + (right-left)/2
		if isBadVersion(mid) {
			res = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	return res
}

func isBadVersion(version int) bool {
	return false
}
