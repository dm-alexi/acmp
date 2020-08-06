package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
)

func fsort(s []byte, rev bool) int {
	sign := 1
	if s[0] == '-' {
		sign = -1
		rev = !rev
		s = s[1:]
	}
	sort.Slice(s, func(i, j int) bool {
		return (s[i] < s[j]) != rev
	})
	if s[0] == '0' && len(s) > 1 {
		for i := 1; i < len(s); i++ {
			if s[i] != '0' {
				s[0], s[i] = s[i], '0'
				break
			}
		}
	}
	r, _ := strconv.Atoi(string(s))
	return r * sign
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s, t string
	fmt.Fscan(f, &s, &t)
	fmt.Fprint(q, fsort([]byte(s), true)-fsort([]byte(t), false))
}
