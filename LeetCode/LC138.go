type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return head
	}
	hash := map[*Node]*Node{}
	root := &Node{
		Val:    head.Val,
		Next:   nil,
		Random: nil,
	}
	hash[head] = root
	for ; head != nil; head = head.Next {
		if _, ok := hash[head.Next]; !ok {
			hash[head.Next] = &Node{Val: head.Next.Val}
		}
		hash[head].Next = hash[head.Next]
		if _, ok := hash[head.Random]; !ok && head.Random != nil {
			hash[head.Random] = &Node{Val: head.Random.Val}
		}
		hash[head].Random = hash[head.Random]
	}
	if _, ok := hash[head.Random]; !ok && head.Random != nil {
		hash[head.Random] = &Node{Val: head.Random.Val}
	}
	hash[head].Random = hash[head.Random]
	return root
}