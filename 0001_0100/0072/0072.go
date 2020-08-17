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
	l := len(s)
	t := []byte(s)
	k, i := l-2, l-1
	for t[k] >= s[k+1] {
		k--
	}
	for t[i] <= t[k] {
		i--
	}
	t[i], t[k] = t[k], t[i]
	for i = 0; i < (l-k-1)/2; i++ {
		t[k+1+i], t[l-1-i] = t[l-1-i], t[k+1+i]
	}
	fmt.Fprint(q, string(t))
}
