package main

import (
	"fmt"
	"sort"
)

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)

	var ret [][]int

	seen := make(map[[4]int]bool)
	size := len(nums)

	for i := 0; i < size-3; i++ {

		if i != 0 && nums[i] == nums[i-1] {
			continue
		}
		//optimalization
		temp_sum_left := nums[i] + nums[i+1] + nums[i+2] + nums[i+3]
		temp_sum_right := nums[i] + nums[size-3] + nums[size-2] + nums[size-1]

		if temp_sum_left > target {
			break
		}

		if temp_sum_right < target {
			continue
		}

		for j := i + 1; j < size-2; j++ {
			left := j + 1
			right := size - 1

			for left < right {
				sum := nums[i] + nums[j] + nums[left] + nums[right]
				if sum < target {
					left++
				} else if sum > target {
					right--
				} else {
					dataToAppend := [4]int{nums[i], nums[j], nums[left], nums[right]}
					if !seen[dataToAppend] {
						ret = append(ret, []int{nums[i], nums[j], nums[left], nums[right]})
						seen[dataToAppend] = true
					}
					left++
					right--
				}
			}
		}
	}

	return ret
}

func main() {
	nums := []int{2, 2, 2, 2, 2}

	ret := fourSum(nums, 8)
	fmt.Println(ret)

	fmt.Println(fourSum([]int{1, 0, -1, 0, -2, 2}, 0))

	fmt.Println(fourSum([]int{-4, -3, -2, -1, 0, 0, 1, 2, 3, 4}, 0))

	fmt.Println(fourSum([]int{0, 4, -5, 2, -2, 4, 2, -1, 4}, 12))
}
