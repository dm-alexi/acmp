package main

import (
	"fmt"
	"os"
	"strings"
)

func count(t []string) int {
	r := 0
	for _, s := range t {
		if len(s) == 4 {
			if s[0] == s[1] && s[:2] == s[2:] {
				r += 5
			} else if s[0] == s[3] && s[1] == s[2] {
				r += 4
			} else if s[:2] == s[2:] || (s[0] == s[1] && s[2] == s[3]) || (s[0] == s[1] && s[0] == s[2]) || (s[0] == s[1] && s[0] == s[3]) || (s[0] == s[2] && s[0] == s[3]) || (s[1] == s[2] && s[1] == s[3]) {
				r += 3
			} else if s[0] == s[2] || s[1] == s[3] {
				r += 2
			}
		} else if len(s) == 3 {
			if s[:2] == s[1:] {
				r += 3
			} else if s[0] == s[1] || s[0] == s[2] || s[1] == s[2] {
				r += 2
			}
		} else if s[0] == s[1] {
			r += 2
		}
	}
	return r
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	fmt.Fscan(f, &s)
	p := [][]string{{s[:4], s[4:]}, {s[:3], s[3:]}, {s[:3], s[3:5], s[5:]}, {s[:2], s[2:5], s[5:]}, {s[:2], s[2:4], s[4:]}}
	m, k := 0, 0
	for i, v := range p {
		if l := count(v); l > m {
			m, k = l, i
		}
	}
	fmt.Fprint(q, strings.Join(p[k], "-"), "\n", m)
}
