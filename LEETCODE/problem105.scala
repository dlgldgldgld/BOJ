object Solution {
   def buildTree(preorder: Array[Int], inorder: Array[Int]): TreeNode = {
    if (preorder.isEmpty) {
      return null
    }
    val len = inorder.indexOf(preorder(0))
    new TreeNode(preorder(0),
      buildTree(preorder.slice(1, 1+len), inorder.slice(0, len)),
      buildTree(preorder.slice(1+len, preorder.length), inorder.slice(len+1, inorder.length))
    )
  }
}