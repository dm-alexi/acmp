package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n, m int
	var p [20222]bool
	a := []string{"2"}
	for i := 3; i < 20222; i += 2 {
		if !p[i] {
			for j := i * i; j < 20222; j += 2 * i {
				p[j] = true
			}
			a = append(a, fmt.Sprint(i))
		}
	}
	s := strings.Join(a, "")
	fmt.Fscan(f, &n)
	for ; n > 0; n-- {
		fmt.Fscan(f, &m)
		fmt.Fprint(q, s[m-1:m])
	}
}
