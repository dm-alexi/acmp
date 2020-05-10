package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, w, d, p int
	fmt.Fscan(f, &n, &w, &d, &p)
	s := (w*n*(n-1)/2 - p) / d
	if s == 0 {
		s = n
	}
	fmt.Fprint(q, s)
}
