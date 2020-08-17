package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b, r int
	for i := 0; i < 4; i++ {
		fmt.Fscan(f, &a, &b)
		r += a - b
	}
	s := "DRAW"
	if r > 0 {
		s = "1"
	} else if r < 0 {
		s = "2"
	}
	fmt.Fprint(q, s)
}
