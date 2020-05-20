package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a, b int
	fmt.Fscan(f, &a, &b)
	fmt.Fprint(q, a+b)
}
