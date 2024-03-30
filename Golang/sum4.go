package main

import (
	"fmt"
	"sort"
	"strconv"
)

func isStored(stored *[][]int, data []int) bool {

	if len(*stored) == 0 {
		return false
	}

	for _, dataStored := range *stored {
		ret := true
		for i := 0; i < len(dataStored); i++ {
			if dataStored[i] != data[i] {
				ret = false
			}
		}

		if ret {
			return ret
		}
	}
	return false
}

func isStoredFaster(storedData *[]string, data string) bool {
	for _, stored := range *storedData {
		if stored == data {
			return true
		}
	}

	*storedData = append(*storedData, data)
	return false
}

func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)

	var ret [][]int

	var storedData []string

	for i := 0; i < len(nums)-3; i++ {
		for j := i + 1; j < len(nums)-2; j++ {
			left := j + 1
			right := len(nums) - 1

			for left < right {
				sum := nums[i] + nums[j] + nums[left] + nums[right]
				if sum < target {
					left++
				} else if sum > target {
					right--
				} else {
					dataToAppend := []int{nums[i], nums[j], nums[left], nums[right]}
					//sort.Ints(dataToAppend)
					//if !isStored(&ret, dataToAppend) {
					if !isStoredFaster(&storedData, strconv.Itoa(dataToAppend[0])+strconv.Itoa(dataToAppend[1])+strconv.Itoa(dataToAppend[2])+strconv.Itoa(dataToAppend[3])) {
						//fmt.Println(strconv.Itoa(dataToAppend[0]) + strconv.Itoa(dataToAppend[1]) + strconv.Itoa(dataToAppend[2]) + strconv.Itoa(dataToAppend[3]))
						ret = append(ret, dataToAppend)
					}
					left++
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
}
