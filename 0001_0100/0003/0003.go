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
	n /= 10
	if n > 0 {
		fmt.Fprint(q, n*(n+1))
	}
	fmt.Fprint(q, "25")
}
