package main

import (
	"fmt"
	"math"
	"os"
)

type dot struct {
	x, y int
}

func sum(a []float64) float64 {
	s := 0.0
	for _, v := range a {
		s += v
	}
	return s
}

func dist(a, b dot) float64 {
	return math.Sqrt(float64((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)))
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	var c, p float64
	r := "NO"
	fmt.Fscan(f, &n, &c, &p)
	t := make([]dot, n+1)
	lens := make([][]float64, n+1)
	for i := 0; i <= n; i++ {
		fmt.Fscan(f, &t[i].x, &t[i].y)
		lens[i] = make([]float64, n+1)
	}
	for i := 1; i < n+1; i++ {
		for j := 0; j < i; j++ {
			lens[i][j] = dist(t[i], t[j])
			lens[j][i] = lens[i][j]
		}
	}
	for i := 0; i < n; i++ {
		if sum(lens[i])*c <= p {
			r = "YES"
			break
		}
	}
	fmt.Fprint(q, r)
}
