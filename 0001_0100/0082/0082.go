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
	s := strings.Fields(string(c))
	var d [100001]byte
	n, _ := strconv.Atoi(s[0])
	a, b := s[2:2+n], s[2+n:]
	for _, v := range a {
		t, _ := strconv.Atoi(v)
		d[t] = 1
	}
	for _, v := range b {
		t, _ := strconv.Atoi(v)
		if d[t] == 1 {
			d[t] = 2
		}
	}
	for i, v := range d {
		if v == 2 {
			fmt.Fprint(q, i, " ")
		}
	}
}
