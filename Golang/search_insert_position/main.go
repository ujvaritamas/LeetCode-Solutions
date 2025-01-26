package main

import "fmt"

func binarySearch(arr []int, low int, high int, x int) int {
	var mid int
	for low <= high {
		mid = low + (high-low)/2

		// Check if x is present at mid
		if arr[mid] == x {
			return mid
		}

		// If x greater, ignore left half
		if arr[mid] < x {
			low = mid + 1
		} else { // If x is smaller, ignore right half
			high = mid - 1
		}
	}

	if x > arr[mid] {
		return mid + 1
	}

	// If we reach here, then element was not present
	return mid
}

func searchInsert(nums []int, target int) int {
	size := len(nums)
	result := binarySearch(nums, 0, size-1, target)
	return result
}

func main() {

	t0 := []int{1, 3, 5, 6}
	t1 := []int{1, 3, 5, 6}

	test := searchInsert(t0, 5)
	fmt.Println(test)

	test = searchInsert(t1, 2)
	fmt.Println(test)
	test = searchInsert(t1, 4)
	fmt.Println(test)
	test = searchInsert(t1, 7)
	fmt.Println(test)
}
