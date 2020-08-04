package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var x1, y1, r1, x2, y2, r2 int
	fmt.Fscan(f, &x1, &y1, &r1, &x2, &y2, &r2)
	m := (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)
	s := "YES"
	if m > (r1+r2)*(r1+r2) || m < (r2-r1)*(r2-r1) {
		s = "NO"
	}
	fmt.Fprint(q, s)
}
