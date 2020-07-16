package main

import (
	"fmt"
	"os"
)

func bet(x, y, x1, y1, x2, y2, x3, y3 float64) bool {
	if x1 == x2 {
		return (x <= x1 && x >= x3) || (x >= x1 && x <= x3)
	} else if y1 == y2 {
		return (y <= y1 && y >= y3) || (y >= y1 && y <= y3)
	}
	t := (y2 - y1) / (x2 - x1)
	return (t*(x-x1)-(y-y1))*(t*(x-x3)-(y-y3)) <= 0
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	var x, y, x1, x2, x3, x4, y1, y2, y3, y4 float64
	fmt.Fscan(f, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(f, &x, &y, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)
		if bet(x, y, x1, y1, x2, y2, x3, y3) && bet(x, y, x1, y1, x4, y4, x2, y2) {
			k++
		}
	}
	fmt.Fprint(q, k)
}
