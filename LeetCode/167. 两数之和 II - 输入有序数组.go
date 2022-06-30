package main

func twoSum(numbers []int, target int) []int {
	for l, r := 0, len(numbers)-1; l < r; {
		sum := numbers[l] + numbers[r]
		if sum == target {
			return []int{l + 1, r + 1}
		} else if sum < target {
			l++
		} else {
			r--
		}
	}

	return nil
}
