package main

import (
	"fmt"
	"math/big"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var k, n int
	fmt.Fscan(f, &k, &n)
	p := []*big.Int{big.NewInt(1), big.NewInt(1)}
	for i := 2; i <= n; i++ {
		p = append(p, new(big.Int).Mul(big.NewInt(2), p[i-1]))
		if i > k {
			p[i] = new(big.Int).Sub(p[i], p[i-k-1])
		}
	}
	fmt.Fprint(q, p[n])
}
