package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	fmt.Fscan(f, &s)
	r := "BLACK"
	if (s[0]-'A'+s[1]-'0')%2 == 0 {
		r = "WHITE"
	}
	fmt.Fprint(q, r)
}
