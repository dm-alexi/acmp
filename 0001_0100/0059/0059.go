package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k, i, s int
	fmt.Fscan(f, &n, &k)
	m := 1
	for n > 0 {
		i = n % k
		s += i
		m *= i
		n /= k
	}
	fmt.Fprint(q, m-s)
}
