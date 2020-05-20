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
	for i := n; i != 0; i &= i - 1 {
		n++
	}
	fmt.Fprint(q, n)
}
