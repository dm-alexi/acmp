package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	var sb strings.Builder
	sb.WriteString("123456789")
	for i := 10; i < 10001; i++ {
		sb.WriteString(strconv.Itoa(i))
	}
	fmt.Fprint(q, strings.Index(sb.String(), strconv.Itoa(n))+1)
}
