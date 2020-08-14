package main

import (
	"fmt"
	"math"
	"os"
)

func main() {
	f, _ := os.Open("input.txt")
	q, _ := os.Create("output.txt")
	var x1, y1, x2, y2, r, s float64
	fmt.Fscan(f, &x1, &y1, &x2, &y2, &r, &s)
	k := math.Sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) / 2
	a := 2 * math.Acos(k/r)
	sn := 2 * math.Pi * r * r
	if k < r {
		sn = r * r * (2*math.Pi - a + math.Sin(a))
	}
	ans := "NO"
	if sn > s {
		ans = "YES"
	}
	fmt.Fprint(q, ans)
}
