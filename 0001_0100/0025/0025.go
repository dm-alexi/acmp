package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b int
	s := "="
	fmt.Fscan(f, &a, &b)
	if a > b {
		s = ">"
	} else if a < b {
		s = "<"
	}
	fmt.Fprint(q, s)
}
