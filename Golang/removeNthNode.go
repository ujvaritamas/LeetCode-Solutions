package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func printLinkedList(head *ListNode) {
	tmp := head
	fmt.Println("ListNode:")
	for tmp != nil {
		fmt.Print(tmp.Val, &tmp, " -> ")
		tmp = tmp.Next
	}
	fmt.Print("nil")
	fmt.Println()
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	ret := head

	var elements []*ListNode

	tmp := head
	size := 0
	for tmp != nil {
		elements = append(elements, tmp)
		tmp = tmp.Next
		size++
	}

	elementToRemove := size - 1 - (n - 1)

	if elementToRemove < 0 {
		return nil
	} else {
		if elementToRemove == 0 {
			ret = head.Next
		} else {
			if elementToRemove == size-1 {
				elements[elementToRemove-1].Next = nil
			} else {
				elements[elementToRemove-1].Next = elements[elementToRemove+1]
			}

		}
	}

	return ret
}

func main() {

	test3 := ListNode{
		Val:  3,
		Next: nil,
	}

	test2 := ListNode{
		Val:  2,
		Next: &test3,
	}

	test1 := ListNode{
		Val:  1,
		Next: &test2,
	}

	printLinkedList(&test1)
	h := removeNthFromEnd(&test1, 4)

	printLinkedList(h)

}
