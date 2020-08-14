package main

import (
	"fmt"
	"os"
)

func readline(f *os.File, n int) []int8 {
	p := make([]int8, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(f, &p[i])
	}
	return p
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, a, b int
	fmt.Fscan(f, &n)
	for ; n > 0; n-- {
		s := "YES"
		fmt.Fscan(f, &a, &b)
		p1 := readline(f, b)
		for i := 1; i < a; i++ {
			p2 := readline(f, b)
			for j := 1; j < b; j++ {
				if p2[j]+p2[j-1]+p1[j]+p1[j-1] == 0 || p2[j]+p2[j-1]+p1[j]+p1[j-1] == 4 {
					s = "NO"
					break
				}
			}
			p1 = p2
		}
		fmt.Fprintln(q, s)
	}
}
