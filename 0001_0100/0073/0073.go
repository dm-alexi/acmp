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
	t := []byte(s)
	d := " abcdefghijklmnopqrstuvwxyz"
	for i := range t {
		if t[i] <= '9' {
			t[i] -= '0'
		} else {
			t[i] -= 'A' - 10
		}
		t[i] = d[(int(t[i])-(i+1)%27+27)%27]
	}
	fmt.Fprint(q, string(t))
}
