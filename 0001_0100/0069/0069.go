package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, a float64
	fmt.Fscan(f, &n, &a)
	r := "NO"
	if a*(1-math.Cos(math.Pi/n))/(2*math.Sin(math.Pi/n)) < 1 {
		r = "YES"
	}
	fmt.Fprint(q, r)
}
