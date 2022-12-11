object problem94 extends App{
  def inorderTraversal(root: TreeNode): List[Int] = {
    if (root == null)
      return List(-1)
    inorderTraversal(root.left):::List(root.value):::inorderTraversal(root.right)
  }
  val in = new TreeNode(1, null, new TreeNode(2, new TreeNode(3, null, null),null))
  inorderTraversal(in)
}
