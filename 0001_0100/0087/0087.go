package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sort"
	"strings"
)

func main() {
	c, _ := ioutil.ReadFile("input.txt")
	q, _ := os.Create("output.txt")
	lines := strings.Fields(string(c))
	n, m := len(lines)-1, 0
	lines = lines[:n]
	sort.Strings(lines)
	p := make(map[string]bool)
	for _, s := range lines {
		p[s] = true
	}
	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if strings.HasPrefix(lines[i], lines[j]) && p[lines[i][len(lines[j]):]] {
				m++
				break
			}
		}
	}
	fmt.Fprint(q, m)
}
