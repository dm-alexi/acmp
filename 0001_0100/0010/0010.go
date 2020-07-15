package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b, c, d, i int64
	fmt.Fscan(f, &a, &b, &c, &d)
	for i = -100; i <= 100; i++ {
		if a*i*i*i+b*i*i+c*i+d == 0 {
			fmt.Fprint(q, i, " ")
		}
	}
}
