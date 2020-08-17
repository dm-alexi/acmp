package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s, m int
	fmt.Fscan(f, &s, &m)
	y := (s + int(math.Sqrt(float64(s*s-4*m)))) / 2
	x := s - y
	if x > y {
		x, y = y, x
	}
	fmt.Fprint(q, x, " ", y)
}
