object problem103 extends App{
  def zigzag(lv:Int, list:List[TreeNode]): List[TreeNode] = {
    lv % 2 match {
      case 1 => list
      case _ => list.reverse
    }
  }

  def zigzagLevelOrder(root: TreeNode): List[List[Int]] = {
    var lv = 0
    LazyList.iterate(Option(root).toList){
      queue => queue.flatMap(node => Option(node.left) ++ Option(node.right))
    }.takeWhile(x => x.nonEmpty).map(
      x => {lv += 1; zigzag(lv, x);}.map(_.value)).toList
  }

  val l = new TreeNode(2, new TreeNode(4,null,null), null)
  val r = new TreeNode(3, null, new TreeNode(5,null,null))

  val ans = zigzagLevelOrder(new TreeNode(1, l, r))
  ans foreach println
}
