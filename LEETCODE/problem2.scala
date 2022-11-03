object problem2 {
  def ListNodeToList( l1 : ListNode ) : List[Int] = {
    var res : List[Int] = List()
    var t_l1 = l1
    while( t_l1 != null ){
      res = res :+ t_l1.x
      t_l1 = t_l1.next
    }
    res
  }


  def addTwoNumbers(l1: ListNode, l2: ListNode): Unit = {
    val ex1 = l1
    val ex2 = l2
    val l1_list = ListNodeToList(ex1)
    val l2_list = ListNodeToList(ex2)
    val zip_all = l1_list.zipAll(l2_list,0 ,0)
    val zip_all_map = zip_all.map(a => a._1 + a._2)

    var res : ListNode = new ListNode(0, null)
    val head = res
    var next = 0
    zip_all_map.zipWithIndex.foreach( a => {
      res.x = (a._1 + next) % 10
      if ( ( a._1 + next ) >= 10 ) next = 1
      else next = 0
      if (zip_all_map.length - 1 > a._2) {
        res.next = new ListNode(-1, null)
        res = res.next
      }
    })
    if ( next == 1 ) res.next = new ListNode(1, null)
    else res = null
    head
  }
}
