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
	if n > 0 {
		n = (1 + n) * n / 2
	} else {
		n = (1-n)*n/2 + 1
	}
	fmt.Fprint(q, n)
}
