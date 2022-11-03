


object problem206 {
  def reverseList(head: ListNode): ListNode = {
    var val_list :Array[Int] = Array()
    var next = head
    while( next != null )
    {
      val_list :+= next.x
      next = next.next
    }

    var ans : ListNode = head
    next = ans
    for( i <- val_list.reverse){
      next.x = i
      next = next.next
    }
    ans
  }
}
