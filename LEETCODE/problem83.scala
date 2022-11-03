object Solution extends App{
  def deleteDuplicates(head: ListNode): ListNode = {
    def helper(ex:Int, curr:ListNode): ListNode = {
      if (curr == null) return null
      if ( ex == curr.x ) {
        helper(ex, curr.next)
      }
      else {
        new ListNode(curr.x, helper(curr.x, curr.next))
      }
    }
    helper(-101, head)
  }

  val t1 = deleteDuplicates(new ListNode(-100, new ListNode(-100, new ListNode(2, new ListNode(3, new ListNode(3, null))))))
  t1.printListNode()

  println()
  val t2 = deleteDuplicates(new ListNode(-100, null))
  t2.printListNode()
}
