package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b int
	fmt.Fscan(f, &a, &b)
	m, n := a, b
	for n > 0 {
		m, n = n, m%n
	}
	fmt.Fprint(q, a/m*b)
}
