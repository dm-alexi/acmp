package main

import (
	"fmt"
	"os"
	"sort"
	"strings"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	var fr, mf, af []string
	fmt.Fscan(f, &n)
	friends := make(map[string]bool)
	s := ""
	for ; n > 0; n-- {
		fmt.Fscan(f, &s)
		fr = append(fr, s)
		friends[s] = true
	}
	fmt.Fscan(f, &n)
	for ; n > 0; n-- {
		fmt.Fscan(f, &s)
		if friends[s] {
			mf = append(mf, s)
		} else {
			af = append(af, s)
		}
	}
	sort.Strings(fr)
	sort.Strings(mf)
	sort.Strings(af)
	fmt.Fprintln(q, "Friends:", strings.Join(fr, ", "))
	fmt.Fprintln(q, "Mutual Friends:", strings.Join(mf, ", "))
	fmt.Fprintln(q, "Also Friend of:", strings.Join(af, ", "))
}
