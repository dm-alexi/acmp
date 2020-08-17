package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	var n int
	fmt.Fscan(f, &s, &n)
	r := "No"
	if s == "Home" || n%2 == 1 {
		r = "Yes"
	}
	fmt.Fprint(q, r)
}
