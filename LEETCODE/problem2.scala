object problem2 {

  def addTwoNumbers(l1: ListNode, l2: ListNode): Unit = {
    var n1 = l1
    var n2 = l2
    var ans = new ListNode(0)
    var curr = ans
    while(n1.next == null && n2.next == null){
      if (n1.next != null) {
        n1 = n1.next
      } else {
        n1 = new ListNode(0, null)
      }

      if (n2.next != null) {
        n2 = n2.next
      } else {
        n2 = new ListNode(0, null)
      }

    }
  }
}
