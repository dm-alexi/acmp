package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	var k float64
	var a, b, c, d int64
	fmt.Fscan(f, &n, &k)
	j := int64(1000 * k)
	r := "Yes"
	for ; n > 0; n-- {
		fmt.Fscan(f, &a, &b, &c, &d)
		if 1000000*(c*c+d*d) > j*j*(a*a+b*b) {
			r = "No"
			break
		}
	}
	fmt.Fprint(q, r)
}
