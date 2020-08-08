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
	fmt.Fprint(q, new(big.Int).Exp(big.NewInt(2), big.NewInt(n), nil))
}
