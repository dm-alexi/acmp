package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	fmt.Fscan(f, &n, &k)
	r := (k - 1) * (k - 1)
	m := k - 1
	for i := 2; i < n; i++ {
		m, r = r, (r+m)*(k-1)
	}
	fmt.Fprint(q, r+m)
}
