package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var w, h, n, x1, y1, x2, y2 int
	fmt.Fscan(f, &w, &h, &n)
	d := make([]bool, w*h)
	for ; n > 0; n-- {
		fmt.Fscan(f, &x1, &y1, &x2, &y2)
		for ; x1 < x2; x1++ {
			for i := y1; i < y2; i++ {
				d[x1*w+i] = true
			}
		}
	}
	for i := range d {
		if d[i] {
			n++
		}
	}
	fmt.Fprint(q, w*h-n)
}
