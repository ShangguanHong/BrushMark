package main

type RecentCounter struct {
	bitmap [3002]int
	start  int
	next   int
}

func Constructor() RecentCounter {
	return RecentCounter{bitmap: [3002]int{}}
}

func (this *RecentCounter) Ping(t int) int {
	this.bitmap[this.next] = t
	this.next++
	if this.next == 3002 {
		this.next = 0
	}

	for this.bitmap[this.start]+3000 < t {
		this.start++
		if this.start == 3002 {
			this.start = 0
		}
	}

	if this.start > this.next {
		return this.next - this.start + 3002
	}

	return this.next - this.start
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */
