package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	d := [4][2]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	t := [101][101]int{}
	x, y, l, k := 50, 50, 0, 0
	t[x][y] = 1
	fmt.Fscan(f, &s)
	for _, c := range s {
		switch c {
		case 'L':
			l = (l + 3) % 4
		case 'R':
			l = (l + 1) % 4
		default:
			x += d[l][0]
			y += d[l][1]
			t[x][y]++
			k++
		}
		if t[x][y] > 1 {
			break
		}
	}
	if t[x][y] < 2 {
		k = -1
	}
	fmt.Fprint(q, k)
}
