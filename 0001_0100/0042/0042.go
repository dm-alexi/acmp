package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int64
	fmt.Fscan(f, &n)
	for k = 1; n > 4; n -= 3 {
		k *= 3
	}
	fmt.Fprint(q, n*k)
}
