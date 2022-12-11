object problem104 extends App{
  def maxDepth(root:TreeNode): Int = {
    if (root == null) {
      return 0
    }
    math.max(maxDepth(root.left), maxDepth(root.right)) + 1
  }
}
