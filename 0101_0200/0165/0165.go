package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m, t int
	fmt.Fscan(f, &n, &m)
	p := make([]int, n*m)
	p[0] = 1
	for i := 0; i < n*m-1; i++ {
		fmt.Fscan(f, &t)
		if p[i] > 0 && t+i%m < m {
			p[t+i] += p[i]
		}
		if p[i] > 0 && t+i/m < n {
			p[t*m+i] += p[i]
		}
	}
	fmt.Fprint(q, p[n*m-1])
}
