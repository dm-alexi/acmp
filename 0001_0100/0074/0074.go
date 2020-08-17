package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k, s int
	fmt.Fscan(f, &n, &k)
	if k == 1 {
		s = n
	} else {
		for k%2 == 1 {
			n /= 2
			s += n
			k = k/2 + 1
		}
	}
	fmt.Fprint(q, s+k/2)
}
