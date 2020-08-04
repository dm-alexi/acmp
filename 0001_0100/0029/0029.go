package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func abs(x int32) int32 {
	y := x >> 31
	return (x ^ y) - y
}

func min(a, b int32) int32 {
	if a < b {
		return a
	}
	return b
}

func main() {
	q, _ := os.Create("output.txt")
	content, _ := ioutil.ReadFile("input.txt")
	d := strings.Fields(string(content))
	n, _ := strconv.Atoi(d[0])
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i], _ = strconv.Atoi(d[i+1])
	}
	var s, prev int32
	if n > 1 {
		s = abs(int32(p[1] - p[0]))
	}
	for i := 2; i < n; i++ {
		s, prev = min(s+abs(int32(p[i]-p[i-1])), prev+3*abs(int32(p[i]-p[i-2]))), s
	}
	fmt.Fprint(q, s)
}
