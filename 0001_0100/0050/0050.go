package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s, t string
	fmt.Fscan(f, &s, &t)
	ls, lt := len(s), len(t)
	t = strings.Repeat(t, 2)
	n := 0
	for i := 0; i < ls-lt+1; i++ {
		for j := 0; j < lt; j++ {
			if s[i:i+lt] == t[j:j+lt] {
				n++
				break
			}
		}
	}
	fmt.Fprint(q, n)
}
