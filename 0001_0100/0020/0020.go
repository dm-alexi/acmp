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
	arr := strings.Fields(string(content))
	max, lres, c := 1, 0, 1
	n, _ := strconv.Atoi(arr[0])
	last, _ := strconv.Atoi(arr[1])
	for i, res := 2, 0; i <= n; i++ {
		cur, _ := strconv.Atoi(arr[i])
		if cur < last {
			res = -1
		} else if cur > last {
			res = 1
		}
		if res == lres || res == 0 {
			if c > max {
				max = c
			}
			if res == 0 {
				c = 0
			} else {
				c = 1
			}
		}
		c++
		lres = res
		last = cur
	}
	if c > max {
		max = c
	}
	fmt.Fprint(q, max)
}
