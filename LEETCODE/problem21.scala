object problem21 {
  def mergeTwoLists(l1: ListNode, l2:ListNode): ListNode = {
    (l1, l2) match {
      case (l1, null) => l1
      case (null, l2) => l2
      case (l1, l2) if l1.x < l2.x => new ListNode(l1.x, mergeTwoLists(l1.next, l2))
      case (l1, l2) => new ListNode(l2.x, mergeTwoLists(l1, l2.next))
    }
  }

  def main(args:Array[String]):Unit = {
    val i1 = new ListNode(1, new ListNode(2, new ListNode(4, null)))
    val i2 = new ListNode(1, new ListNode(3, new ListNode(4, null)))
    val ans = mergeTwoLists(i1, i2)
    print(ans)
  }
}
