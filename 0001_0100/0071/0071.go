package main

import (
	"fmt"
	"os"
)

func abs(x int32) int32 {
	y := x >> 31
	return (x ^ y) - y
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s int32
	var n int
	fmt.Fscan(f, &n)
	p := make([]int32, n)
	for i := range p {
		fmt.Fscan(f, &p[i])
		s += p[i]
	}
	for i, m := 1, 1<<uint(n-1); s > 0 && i < m; i++ {
		k, t := p[0], i
		for j := 1; j < n; j++ {
			if t&1 == 1 {
				k -= p[j]
			} else {
				k += p[j]
			}
			t >>= 1
		}
		if abs(k) < s {
			s = abs(k)
		}
	}
	fmt.Fprint(q, s)
}
