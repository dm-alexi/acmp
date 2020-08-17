package main

import (
	"fmt"
	"math/big"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	a, r := big.NewInt(45), big.NewInt(1)
	for n > 0 {
		if n&1 == 1 {
			r = r.Mul(r, a)
		}
		a = a.Mul(a, a)
		n >>= 1
	}
	fmt.Fprint(q, r)
}
