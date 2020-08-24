package main

import (
	"fmt"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	r := "Correct"
	var n int
	fmt.Fscan(f, &n)
	t := make([][]byte, n*n)
	for i := 0; i < n*n; i++ {
		t[i] = make([]byte, n*n)
		for j := 0; j < n*n; j++ {
			fmt.Fscan(f, &t[i][j])
			if int(t[i][j]) > n*n {
				r = "Incorrect"
			}
		}
	}
	for i := 0; i < n*n && r == "Correct"; i++ {
		j, l, c, k := 0, make([]byte, n*n+1), make([]byte, n*n+1), make([]byte, n*n+1)
		for ; j < n*n; j++ {
			l[t[i][j]]++
			c[t[j][i]]++
			k[t[i/n*n+j/n][i%n*n+j%n]]++
		}
		for j = 1; j <= n*n && l[j] == 1 && c[j] == 1 && k[j] == 1; j++ {
		}
		if j <= n*n {
			r = "Incorrect"
		}
	}
	fmt.Fprint(q, r)
}
