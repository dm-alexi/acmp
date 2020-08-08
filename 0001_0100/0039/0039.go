package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	p := make([]int, n)
	for i := range p {
		fmt.Fscan(f, &p[i])
	}
	s := 0
	for i := 0; i < n; i++ {
		m := i
		for j := i; j < n; j++ {
			if p[j] > p[m] {
				m = j
			}
		}
		s += (m - i + 1) * p[m]
		i = m
	}
	fmt.Fprint(q, s)
}
