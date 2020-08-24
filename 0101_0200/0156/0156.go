package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	kf, nf := 1, 1
	fmt.Fscan(f, &n, &k)
	for i := 1; i <= k; i++ {
		kf *= i
		nf *= n - i + 1
	}
	fmt.Fprint(q, nf*nf/kf)
}
