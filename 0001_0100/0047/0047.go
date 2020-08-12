package main

import (
	"fmt"
	"os"
)

func sum(n int) int {
	s := 0
	for n > 0 {
		s += n % 10
		n /= 10
	}
	return s
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	d, s := 1, 1
	for i := 2; i <= n/2; i++ {
		if n%i == 0 && sum(i) > s {
			d, s = i, sum(i)
		}
	}
	if sum(n) > s {
		d = n
	}
	fmt.Fprint(q, d)
}
