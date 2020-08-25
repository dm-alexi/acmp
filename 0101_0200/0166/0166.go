package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	var p [3]int
	l := []int{0, 0, 0, 5, 5, 9, 10, 10, 14, 15, 18, 19, 20, 23, 24, 27, 28, 29, 32, 33}
	fmt.Fscan(f, &k, &n)
	for p[0] = k; n > 1; n-- {
		p[2], p[1] = p[1], p[0]
		switch {
		case k < 20:
			p[0] = l[k]
		case k%20 < 10:
			p[0] = (k/10-1)*18 + l[k%20+10]
		default:
			p[0] = k/20*36 + l[k%20]
		}
		k = p[0] + p[1] + p[2]
	}
	fmt.Fprint(q, k)
}
