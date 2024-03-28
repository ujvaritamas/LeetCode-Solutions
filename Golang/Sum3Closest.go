package main

import (
	"fmt"
	"math"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func threeSumClosest(nums []int, target int) int {
	sort.Ints(nums)

	closestSum := math.MaxInt32
	minDiff := math.MaxInt32

	for i := 0; i < len(nums)-2; i++ {
		// Initialize pointers for two sum problem
		left, right := i+1, len(nums)-1

		// Perform two pointer approach
		for left < right {
			sum := nums[i] + nums[left] + nums[right]
			diff := abs(sum - target)
			if diff < minDiff {
				minDiff = diff
				closestSum = sum
			}

			// Move pointers based on the sum
			if sum < target {
				left++
			} else if sum > target {
				right--
			} else {
				return sum
			}
		}
	}
	return closestSum
}

func main() {
	test := []int{-1, 2, 1, -4}

	fmt.Println(threeSumClosest(test[:], 1))

}
