package main

import (
	"fmt"
	"math/big"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int64
	fmt.Fscan(f, &n)
	k := big.NewInt(1)
	for ; n > 1; n-- {
		k.Mul(k, big.NewInt(n))
	}
	fmt.Fprint(q, k)
}
