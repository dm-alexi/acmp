package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int64
	fmt.Fscan(f, &n, &k)
	fmt.Fprint(q, n+(2+(2+k)*(n-2))*(k-1)/2)
}
