object problem100 {
  def isSameTree(p: TreeNode, q: TreeNode): Boolean = {
    if ((p == null && q != null) || (p != null && q == null)) return false
    if (p == null && q == null) return true
    val res = p.value == q.value
    res || isSameTree(p.left, q.left) || isSameTree(p.right, q.right)
  }
}
