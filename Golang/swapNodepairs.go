/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func swap(prev *ListNode, current *ListNode, next *ListNode) *ListNode{
    fmt.Println("Swap")
    fmt.Println(prev, current, next)

    if prev == nil{
        current.Next = next.Next
        next.Next = current
    } else {
        prev.Next = next
        current.Next = next.Next
        next.Next = current
    }
    fmt.Println(prev, current, next)
    return current
}

func swapPairs(head *ListNode) *ListNode {
    ret := head
    current := head
    if current == nil{
        return head
    }

    n:= current.Next
    if n == nil{
        return head
    }

    nn := n.Next
    if nn==nil{
        swap(nil, current, n)
        ret = n
        return ret
    }
    ret = n
    current = swap(nil, current, n)

    for current != nil{
        n = current.Next

        if n == nil {
            return ret
        } else {
            nn = n.Next
            if nn == nil {
                return ret
            }
            current = swap(current, n, nn)

        }
    }
    return ret
}