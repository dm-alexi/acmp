package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	fmt.Fscan(f, &s)
	n := len(s) - 1
	for s[n] == '0' {
		n--
	}
	fmt.Fprint(q, "1", s[n+1:])
}
