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
	fmt.Fprint(q, k-1, n-1)
}
