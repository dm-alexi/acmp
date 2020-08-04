package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, i, j int
	fmt.Fscan(f, &n)
	p := make([]int, n)
	for ; i < n; i++ {
		fmt.Fscan(f, &p[i])
	}
	for i = 1; i < n; i++ {
		if (n-1)%i == 0 && p[i] == p[0] {
			for j = i; j < n; j++ {
				if p[j] != p[j%i] {
					break
				}
			}
			if j == n {
				break
			}
		}
	}
	fmt.Fprint(q, i)
}
