package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	fmt.Fscan(f, &s)
	n := 0
	for _, v := range strings.Split(s, "1") {
		if len(v) > n {
			n = len(v)
		}
	}
	fmt.Fprint(q, n)
}
