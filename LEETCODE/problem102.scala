object problem102 {
  var answer:List[List[Int]] = List()
  def traverse(nodes: List[TreeNode], lv:Int): Unit= {
    if (nodes.isEmpty) {
      return
    }
    var n_node:List[TreeNode] = List()
    var nodeList:List[Int] = List()
    for (node <- if(lv%2 == 0) nodes else nodes.reverse) {
      if (node != null) {
        nodeList = node.value::nodeList
        if (node.right != null)
          n_node = n_node :+ node.right
        if (node.left != null)
          n_node = n_node :+ node.left
      }
    }
    answer = answer.appended(nodeList)
    traverse(n_node, lv+1)
  }

  def levelOrder(root: TreeNode): List[List[Int]] = {
    answer = List()
    if (root == null){
      return answer
    }
    traverse(List(root), 0)
    answer
  }

  def levelOrder2(root: TreeNode): List[List[Int]] = {
    // iterate 무한 반복

    LazyList.iterate(Option(root).toList) { queue =>
      // queue는 list로 시작하므로 flatMap을 통해서 펼쳐줌. Option을 통해서 연산 진행시 null 처리가 가능함.
      // Option(null).toList => List가 됨. ++ iterableOps 연산을 통해서 Seq appended가 가능해짐.
      queue.flatMap(node => (Option(node.left) ++ Option(node.right)).toList)
    }.takeWhile(x => x.nonEmpty).map(_.map(_.value)).toList
    // x.Empty가 될때까지 계속 반복. LazyList[List[TreeNode]]의 내부 값 List를 순회하며 TreeNode를 value로 변경.
    // 마지막으로 LazyList를 List로 변경.
  }
}
