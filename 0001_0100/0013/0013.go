package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var b, k byte
	var s, t string
	fmt.Fscan(f, &s, &t)
	for i, c := range s {
		if c == rune(t[i]) {
			b++
		} else if strings.ContainsRune(t, c) {
			k++
		}
	}
	fmt.Fprint(q, b, k)
}
