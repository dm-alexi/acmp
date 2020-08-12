package main

import (
	"fmt"
	"os"
)

func count(n int) int {
	s := 0
	for ; n > 0; n &= n - 1 {
		s++
	}
	return s
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s, t string
	fmt.Fscan(f, &s, &t)
	set := make(map[byte]int)
	for i := byte('0'); i <= '9'; i++ {
		set[i] = 1 << (i - '0')
	}
	for i := byte('a'); i <= 'g'; i++ {
		set[i] = 15 << (i - 'a')
	}
	set['?'] = 1023
	n := 1
	for i := 0; i < len(s) && n > 0; i++ {
		n *= count(set[s[i]] & set[t[i]])
	}
	fmt.Fprint(q, n)
}
