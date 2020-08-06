package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	var s string
	r := "NO"
	fmt.Fscan(f, &n, &k, &s)
	m := make(map[string]int)
	for i := 0; i <= n-k; i++ {
		m[s[i:i+k]] = 1
		if len(m) == i {
			r = "YES"
			break
		}
	}
	fmt.Fprint(q, r)
}
