package main

import (
	"fmt"
	"os"
)

func clear(m []bool, n int, x int, y int) bool {
	for i := 0; i < x; i++ {
		if m[i*n+y] {
			return false
		}
	}
	for i := 0; i < y; i++ {
		if m[x*n+i] {
			return false
		}
	}
	for i := 1; x-i >= 0 && y-i >= 0; i++ {
		if m[(x-i)*n+y-i] {
			return false
		}
	}
	for i := 1; x-i >= 0 && y+i < n; i++ {
		if m[(x-i)*n+y+i] {
			return false
		}
	}
	return !((x > 0 && y > 1 && m[(x-1)*n+y-2]) || (x > 0 && y < n-2 && m[(x-1)*n+y+2]) || (x > 1 && y > 0 && m[(x-2)*n+y-1]) || (x > 1 && y < n-1 && m[(x-2)*n+y+1]))
}

func put(m []bool, n int, k int, start int, ct []int) {
	for i := start; i <= n-k+ct[0]; i++ {
		for j := 0; j < n; j++ {
			if clear(m, n, i, j) {
				m[i*n+j] = true
				if ct[0]++; ct[0] == k {
					ct[1]++
				} else {
					put(m, n, k, i+1, ct)
				}
				m[i*n+j] = false
				ct[0]--
			}
		}
	}
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	ct := make([]int, 2)
	fmt.Fscan(f, &n, &k)
	m := make([]bool, n*n)
	put(m, n, k, 0, ct)
	fmt.Fprint(q, ct[1])
}
