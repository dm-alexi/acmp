package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func diff(a, b string) int {
	s := 0
	for i := range a {
		if a[i] != b[i] {
			s++
		}
	}
	return s
}

func main() {
	content, _ := ioutil.ReadFile("input.txt")
	q, _ := os.Create("output.txt")
	a := strings.Fields(string(content))
	n, _ := strconv.Atoi(a[1])
	var p []int
	m := len(a[0])
	for i := 2; i < n+2; i++ {
		d := diff(a[0], a[i])
		if d <= m {
			p = append(p, i-1)
			if d < m {
				m = d
				p = p[len(p)-1:]
			}
		}
	}
	fmt.Fprint(q, len(p), "\n", strings.Trim(fmt.Sprint(p), "[]"))
}
