package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var n int
	fmt.Fscan(f, &n)
	i := (int(math.Sqrt(float64(n*8-3)))-1)/2 + 1
	for ; i > 1 && !(n > (i-1)*i/2 && (n-((i-1)*i/2))%i == 0); i-- {
	}
	fmt.Fprint(q, i)
}
