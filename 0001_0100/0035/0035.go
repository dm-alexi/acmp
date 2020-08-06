package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var k, n, m int
	fmt.Fscan(f, &k)
	for ; k > 0; k-- {
		fmt.Fscan(f, &n, &m)
		fmt.Fprintln(q, 19*m+(n+239)*(n+366)/2)
	}
}
