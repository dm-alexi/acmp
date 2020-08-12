package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	var s string
	fmt.Fscan(f, &n)
	if n == 0 {
		s = "10"
	} else if n == 1 {
		s = "1"
	} else {
		var a [10]int
		for i := 9; i > 1; i-- {
			for n%i == 0 {
				n /= i
				a[i]++
			}
		}
		if n > 1 {
			s = "-1"
		} else {
			for i := 2; i < 10; i++ {
				s += strings.Repeat(fmt.Sprint(i), a[i])
			}
		}
	}
	fmt.Fprint(q, s)
}
