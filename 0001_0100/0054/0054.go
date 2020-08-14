package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m, k int
	fmt.Fscan(f, &n, &m)
	maxmin, minmax := -1000, 1000
	p := make([]int, m)
	for i := 0; i < m; i++ {
		p[i] = -1000
	}
	for ; n > 0; n-- {
		min := 1000
		for i := 0; i < m; i++ {
			fmt.Fscan(f, &k)
			if k < min {
				min = k
			}
			if k > p[i] {
				p[i] = k
			}
		}
		if min > maxmin {
			maxmin = min
		}
	}
	for i := 0; i < m; i++ {
		if p[i] < minmax {
			minmax = p[i]
		}
	}
	fmt.Fprint(q, maxmin, " ", minmax)
}
