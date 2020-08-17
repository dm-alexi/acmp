package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func readIP(s string) uint {
	t := strings.Split(s, ".")
	a, _ := strconv.ParseUint(t[0], 0, 0)
	b, _ := strconv.ParseUint(t[1], 0, 0)
	c, _ := strconv.ParseUint(t[2], 0, 0)
	d, _ := strconv.ParseUint(t[3], 0, 0)
	return uint((((((a << 8) | b) << 8) | c) << 8) | d)
}

func main() {
	c, _ := ioutil.ReadFile("input.txt")
	q, _ := os.Create("output.txt")
	s := strings.Fields(string(c))
	n, _ := strconv.Atoi(s[0])
	p := make([]uint, n)
	for i := range p {
		p[i] = readIP(s[i+1])
	}
	m, _ := strconv.Atoi(s[n+1])
	for i := 0; i < 2*m; i += 2 {
		k := 0
		x, y := readIP(s[n+i+2]), readIP(s[n+i+3])
		for _, v := range p {
			if x&v == y&v {
				k++
			}
		}
		fmt.Fprintln(q, k)
	}
}
