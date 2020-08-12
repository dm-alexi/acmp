package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	q, _ := os.Create("output.txt")
	content, _ := ioutil.ReadFile("input.txt")
	d := strings.Fields(string(content))
	n, _ := strconv.Atoi(d[0])
	var p [201]int
	for i := 1; i <= n; i++ {
		j, _ := strconv.Atoi(d[i])
		p[j+100]++
	}
	for i := 0; i < 201; i++ {
		fmt.Fprint(q, strings.Repeat(fmt.Sprint(i-100, " "), p[i]))
	}
}
