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
	p := make([]bool, 2*n)
	for i := 2; i < n; i++ {
		if !p[i] {
			for j := 2 * i; j < 2*n; j += i {
				p[j] = true
			}
		}
	}
	k := 0
	for i := n + 1; i < 2*n; i++ {
		if !p[i] {
			k++
		}
	}
	fmt.Fprint(q, k)
}
