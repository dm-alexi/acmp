package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var x1, y1, x2, y2, x, y int
	fmt.Fscan(f, &x1, &y1, &x2, &y2, &x, &y)
	if x1 == x2 {
		x = 2*x1 - x
	} else {
		y = 2*y1 - y
	}
	fmt.Fprint(q, x, " ", y)
}
