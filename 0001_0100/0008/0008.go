package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b, c int
	fmt.Fscan(f, &a, &b, &c)
	if a*b == c {
		fmt.Fprint(q, "YES")
	} else {
		fmt.Fprint(q, "NO")
	}
}
