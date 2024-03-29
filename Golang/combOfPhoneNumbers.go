package main

import (
	"fmt"
	"strconv"
)

var buttons = map[int][]string{
	2: {"a", "b", "c"},
	3: {"d", "e", "f"},
	4: {"g", "h", "i"},
	5: {"j", "k", "l"},
	6: {"m", "n", "o"},
	7: {"p", "q", "r", "s"},
	8: {"t", "u", "v"},
	9: {"w", "x", "y", "z"},
}

func combine(inp0 []string, inp1 []string, inp2 []string, inp3 []string) []string {
	var ret []string
	if len(inp0) > 0 {
		for i := 0; i < len(inp0); i++ {
			if len(inp1) > 0 {
				for j := 0; j < len(inp1); j++ {
					if len(inp2) > 0 {
						for k := 0; k < len(inp2); k++ {
							if len(inp3) > 0 {
								for l := 0; l < len(inp3); l++ {
									ret = append(ret, string(inp0[i])+string(inp1[j])+string(inp2[k])+string(inp3[l]))
								}
							} else {
								ret = append(ret, string(inp0[i])+string(inp1[j])+string(inp2[k]))
							}
						}
					} else {
						ret = append(ret, string(inp0[i])+string(inp1[j]))
					}
				}
			} else {
				ret = append(ret, string(inp0[i]))
			}
		}
	} else {
		return ret
	}
	return ret
}

func letterCombinations(digits string) []string {

	var ret []string

	var pos [][]string

	for i := 0; i < len(digits); i++ {
		num, _ := strconv.Atoi(string(digits[i]))
		pos = append(pos, buttons[num])
	}

	//handle if size < 4 (description: max 4 number used)
	size := len(pos)
	if size < 4 {
		for i := 0; i < 4-size; i++ {
			pos = append(pos, nil)
		}
	}
	ret = combine(pos[0], pos[1], pos[2], pos[3])

	return ret
}

func main() {
	test := "5678"
	r := letterCombinations(test)

	fmt.Println(r)
}
