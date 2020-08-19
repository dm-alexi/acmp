package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var min, max, n, t int
	fmt.Fscan(f, &n, &min)
	for max = min; n > 1; n-- {
		fmt.Fscan(f, &t)
		if t > max {
			max = t
		} else if t < min {
			min = t
		}
	}
	fmt.Fprint(q, min, " ", max)
}
