package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m int
	fmt.Fscan(f, &n, &m)
	t := make([][]int, n)
	for i := 0; i < n; i++ {
		t[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(f, &t[i][j])
		}
	}
	for i := 1; i < n; i++ {
		t[i][0] += t[i-1][0]
	}
	for j := 1; j < m; j++ {
		t[0][j] += t[0][j-1]
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if t[i-1][j] < t[i][j-1] {
				t[i][j] += t[i-1][j]
			} else {
				t[i][j] += t[i][j-1]
			}
		}
	}
	fmt.Fprint(q, t[n-1][m-1])
}
