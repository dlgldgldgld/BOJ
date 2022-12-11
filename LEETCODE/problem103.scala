object problem103 extends App{
  def zigzag(lv:Int, list:List[TreeNode]): List[TreeNode] = {
    lv % 2 match {
      case 0 => list
      case _ => list.reverse
    }
  }

  def zigzagLevelOrder(root: TreeNode): List[List[Int]] = {
    LazyList.iterate(Option(root).toList){
      queue => queue.flatMap(node => Option(node.left) ++ Option(node.right))
    }.takeWhile(x => x.nonEmpty).zipWithIndex.map(
      x => {zigzag(x._2, x._1)}.map(_.value)).toList
  }

  val l = new TreeNode(2, new TreeNode(4,null,null), null)
  val r = new TreeNode(3, null, new TreeNode(5,null,null))

  val ans = zigzagLevelOrder(new TreeNode(1, l, r))
  ans foreach println
}
