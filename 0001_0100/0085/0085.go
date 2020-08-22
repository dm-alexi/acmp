package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b int
	fmt.Fscan(f, &a, &b)
	for b > 0 {
		a, b = b, a%b
	}
	fmt.Fprint(q, strings.Repeat("1", a))
}
