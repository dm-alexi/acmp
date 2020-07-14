package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, k int
	var s []int
	fmt.Fscan(f, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(f, &k)
		if k%2 == 1 {
			fmt.Fprint(q, k, " ")
		} else {
			s = append(s, k)
		}
	}
	fmt.Fprintln(q)
	for _, val := range s {
		fmt.Fprint(q, val, " ")
	}
	if 2*len(s) >= n {
		fmt.Fprint(q, "\nYES")
	} else {
		fmt.Fprint(q, "\nNO")
	}
}
