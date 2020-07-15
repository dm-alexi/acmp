package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var s string
	fmt.Fscan(f, &s)
	if len(s) != 5 || s[0] < 'A' || s[0] > 'H' || s[3] < 'A' || s[3] > 'H' || s[1] < '1' || s[1] > '8' || s[4] < '1' || s[4] > '8' || s[2] != '-' {
		fmt.Fprint(q, "ERROR")
	} else if x := (int(s[0]) - int(s[3])) * (int(s[1]) - int(s[4])); x == 2 || x == -2 {
		fmt.Fprint(q, "YES")
	} else {
		fmt.Fprint(q, "NO")
	}
}
