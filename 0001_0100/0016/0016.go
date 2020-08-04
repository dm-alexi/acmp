package main

import (
	"fmt"
	"os"
)

func layer(n, k int) int {
	if n > k*(k+1)/2 {
		return 0
	} else if n < 3 || n == k*(k+1)/2 {
		return 1
	} else if k > n {
		k = n
	}
	d := 0
	for ; k >= n-k*(k+1)/2; k-- {
		d += layer(n-k, k-1)
	}
	return d
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	fmt.Fprint(q, layer(n, n))
}
