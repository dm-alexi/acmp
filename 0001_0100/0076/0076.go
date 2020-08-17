package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	c, _ := ioutil.ReadFile("input.txt")
	q, _ := os.Create("output.txt")
	var n, m int
	var s [1440]int

	t := strings.Fields(string(c))
	n, _ = strconv.Atoi(t[0])
	for i := 1; i < n*2; i += 2 {
		a, _ := strconv.Atoi(t[i][:2])
		b, _ := strconv.Atoi(t[i][3:5])
		c, _ := strconv.Atoi(t[i+1][:2])
		d, _ := strconv.Atoi(t[i+1][3:5])
		for j := a*60 + b; j <= c*60+d; j++ {
			s[j]++
		}
	}
	for i := 0; i < 1440; i++ {
		if s[i] > m {
			m = s[i]
		}
	}
	fmt.Fprint(q, m)
}
