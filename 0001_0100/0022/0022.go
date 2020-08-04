package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var x, n uint
	fmt.Fscan(f, &x)
	for n = 0; x != 0; n++ {
		x &= x - 1
	}
	fmt.Fprint(q, n)
}
