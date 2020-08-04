package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, s int
	fmt.Fscan(f, &n)
	for i := n * n; i > 0; i-- {
		fmt.Fscan(f, &n)
		s += n
	}
	fmt.Fprint(q, s/2)
}
