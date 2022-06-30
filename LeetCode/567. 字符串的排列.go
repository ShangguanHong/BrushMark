package main

func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}

	equal := func(record1, record2 map[uint8]int) bool {
		for k, v := range record1 {
			if vv := record2[k]; v != vv {
				return false
			}
		}

		return true
	}

	var record1 = map[uint8]int{}
	var record2 = map[uint8]int{}
	for i := 0; i < len(s1); i++ {
		record1[s1[i]]++
		record2[s2[i]]++
	}

	if equal(record1, record2) {
		return true
	}

	for r := len(s1); r < len(s2); r++ {
		record2[s2[r-len(s1)]]--
		record2[s2[r]]++

		if equal(record1, record2) {
			return true
		}
	}

	return false
}
