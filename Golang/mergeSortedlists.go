package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func printLinkedList(list *ListNode) {
	e := list
	for e != nil {
		fmt.Print(e.Val, " -> ")
		e = e.Next
	}
	fmt.Println("*")
}

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

	res := &ListNode{}
	resFirstelement := res

	for list1 != nil && list2 != nil {
		if res == nil {
			if list1.Val > list2.Val {
				res.Val = list2.Val
				list2 = list2.Next
			} else {
				res.Val = list1.Val
				list1 = list1.Next
			}
		} else {
			if list1.Val > list2.Val {
				res.Next = &ListNode{list2.Val, nil}
				list2 = list2.Next
			} else {
				res.Next = &ListNode{list1.Val, nil}
				list1 = list1.Next
			}
		}
		res = res.Next
	}

	if list1 != nil {
		if res == nil {
			res = list1
		} else {
			res.Next = list1
		}
	}

	if list2 != nil {
		if res == nil {
			res = list2
		} else {
			res.Next = list2
		}
	}

	//remove the first element dummy value
	return resFirstelement.Next
}

func main() {

	e0 := ListNode{4, nil}
	e1 := ListNode{2, &e0}
	e2 := ListNode{1, &e1}

	ee0 := ListNode{4, nil}
	ee1 := ListNode{3, &ee0}
	ee2 := ListNode{1, &ee1}

	res := mergeTwoLists(&e2, &ee2)

	printLinkedList(res)

}
