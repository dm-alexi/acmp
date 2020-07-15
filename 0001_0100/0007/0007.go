package main

import (
	"fmt"
	"os"
)

func max(a, b string) string {
	if len(a) > len(b) || (len(a) == len(b) && a > b) {
		return a
	}
	return b
}

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b, c string
	fmt.Fscanf(f, "%s %s %s", &a, &b, &c)
	fmt.Fprint(q, max(max(a, b), c))
}
