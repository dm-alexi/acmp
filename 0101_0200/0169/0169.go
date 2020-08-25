package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k, r int
	fmt.Fscan(f, &n, &k)
	if n == k {
		r = 1
	} else if n%2 == k%2 {
		p := make([]int, k)
		p[0] = 1
		for i := 2; i <= k; i++ {
			t := p[1]
			for j := i%2 + 1; j < k-1; j += 2 {
				p[j] = p[j-1] + p[j+1]
			}
			p[0] = t
		}
		r = p[n-1]
	}
	fmt.Fprint(q, r)
}
