package main

import (
	"fmt"
	"os"
)

func abs(x int8) int8 {
	y := x >> 7
	return (x ^ y) - y
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	get := func() (int8, int8) {
		var s string
		fmt.Fscan(f, &s)
		return int8(s[0] - 'A'), int8(s[1] - '1')
	}
	qx, qy := get()
	rx, ry := get()
	kx, ky := get()
	n := 0
	for i := int8(0); i < 8; i++ {
		if i == qx || i == rx {
			n += 8
		} else {
			for j := int8(0); j < 8; j++ {
				if j == qy || j == ry || abs(qx-i) == abs(qy-j) || abs((kx-i)*(ky-j)) == 2 || (i == kx && j == ky) {
					n++
				}
			}
		}
	}
	fmt.Fprint(q, n-3)
}
