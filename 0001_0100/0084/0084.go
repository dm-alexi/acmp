package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m, xmax, ymax int
	var s string
	fmt.Fscan(f, &n, &m)
	ymin, xmin := n, m
	for i := 0; i < n; i++ {
		fmt.Fscan(f, &s)
		if k := strings.Index(s, "*"); k > -1 {
			if i < ymin {
				ymin = i
			}
			ymax = i
			if k < xmin {
				xmin = k
			}
			if k = strings.LastIndex(s, "*"); k > xmax {
				xmax = k
			}
		}
	}
	a := strings.Repeat(".", m) + "\n"
	b := strings.Repeat(".", xmin) + strings.Repeat("*", xmax+1-xmin) + strings.Repeat(".", m-xmax-1) + "\n"
	for i := 0; i < n; i++ {
		if i < ymin || i > ymax {
			fmt.Fprint(q, a)
		} else {
			fmt.Fprint(q, b)
		}
	}
}
