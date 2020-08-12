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
	n := 0
	for i := 0; i < len(s)-4; i++ {
		if s[i:][:5] == ">>-->" || s[i:][:5] == "<--<<" {
			n++
		}
	}
	fmt.Fprint(q, n)
}
