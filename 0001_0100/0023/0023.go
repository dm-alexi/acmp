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
	s := n
	for i := 1; i <= n/2; i++ {
		if n%i == 0 {
			s += i
		}
	}
	fmt.Fprint(q, s)
}
