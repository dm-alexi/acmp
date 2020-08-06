package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s, mini, maxi, n int
	fmt.Fscan(f, &n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(f, &p[i])
		if p[i] > 0 {
			s += p[i]
		}
		if p[mini] > p[i] {
			mini = i
		} else if p[maxi] < p[i] {
			maxi = i
		}
	}
	m := 1
	if mini > maxi {
		mini, maxi = maxi, mini
	}
	for i := mini + 1; i < maxi; i++ {
		m *= p[i]
	}
	fmt.Fprint(q, s, m)
}
