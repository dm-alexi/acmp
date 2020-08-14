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
	r := "NO"
	if s[0]+s[1]+s[2]-s[3]-s[4]-s[5] == 0 {
		r = "YES"
	}
	fmt.Fprint(q, r)
}
