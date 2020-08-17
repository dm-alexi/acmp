package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	var s string
	fmt.Fscan(f, &s, &n)
	r, l := "NO SOLUTION", len(s)
	if n > 0 {
		r = s
		for ; n > 1 && len(r) < 1023; n-- {
			r += s
		}
		if len(r) > 1023 {
			r = r[:1023]
		}
	} else if l%n == 0 && strings.Repeat(s[:-l/n], -n) == s {
		r = s[:-l/n]
	}
	fmt.Fprint(q, r)
}
