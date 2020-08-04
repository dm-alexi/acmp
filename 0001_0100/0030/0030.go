package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var a [10]int
	var s, t [3]int
	fmt.Fscanf(f, "%d:%d:%d\n%d:%d:%d", &s[0], &s[1], &s[2], &t[0], &t[1], &t[2])
	for {
		for _, v := range s {
			a[v/10]++
			a[v%10]++
		}
		if s == t {
			break
		}
		if s[2]++; s[2] == 60 {
			s[2] = 0
			if s[1]++; s[1] == 60 {
				s[1] = 0
				s[0]++
			}
		}
	}
	for _, v := range a {
		fmt.Fprintln(q, v)
	}
}
