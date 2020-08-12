package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	s := "2.7182818284590452353602875"
	fmt.Fscan(f, &n)
	if n == 0 {
		s = "3"
	} else if n < 25 {
		if s[n+2] >= '5' {
			s = fmt.Sprintf("%s%c", s[:n+1], s[n+1]+1)
		} else {
			s = s[:n+2]
		}
	}
	fmt.Fprint(q, s)
}
