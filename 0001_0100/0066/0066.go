package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	s := "qwertyuiopasdfghjklzxcvbnmq"
	var c string
	fmt.Fscan(f, &c)
	fmt.Fprint(q, string(s[strings.Index(s, c)+1]))
}
