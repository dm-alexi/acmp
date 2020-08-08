package main

import (
	"fmt"
	"os"
)

const KEY = 100000

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func play(p, t []int, left, right, n int) int {
	if t[left*n+right] == KEY {
		t[left*n+right] = max(p[left]-play(p, t, left+1, right, n), p[right]-play(p, t, left, right-1, n))
	}
	return t[left*n+right]
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	t := make([]int, n*n)
	for i := range t {
		t[i] = KEY
	}
	p := make([]int, n)
	for i := range p {
		fmt.Fscan(f, &p[i])
		t[n*i+i] = p[i]
	}
	n = func(r int) int {
		if r > 0 {
			return 1
		} else if r < 0 {
			return 2
		}
		return 0
	}(play(p, t, 0, n-1, n))
	fmt.Fprint(q, n)
}
