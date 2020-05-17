package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	st := 1
	fmt.Fscan(f, &n)
	if n%4 > 0 {
		st++
		fmt.Fprintf(q, "1 1 0 1\n")
		switch {
		case n%4 == 3:
			fmt.Fprintf(q, "1 2 2 %d\n", n)
			n--
		case n > 1:
			fmt.Fprintf(q, "1 2 2 0\n")
		}
		if n > 2 && n%4 == 1 {
			fmt.Fprintf(q, "2 1 0 3\n2 2 4 %d\n", n)
			n--
			st++
		}
	}
	for i := st; 2*i < n; i++ {
		fmt.Fprintf(q, "%d 1 %d %d\n%d 2 %d %d\n", i, n, 2*i-1, i, 2*i, n-1)
		n -= 2
	}
}
