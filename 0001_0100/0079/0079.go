package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	s := "0000111162481397646455556666179368421919"
	var a, b int
	fmt.Fscan(f, &a, &b)
	fmt.Fprint(q, string(s[a%10*4+b%4]))
}
