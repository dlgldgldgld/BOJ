object problem20 {
  def isValid(s:String): Boolean = {
    def check(s: String, stack: List[Char], c_idx: Int, length: Int): Boolean = {
      if (c_idx == length) {
        if (stack.length > 0) false
        else true
      }
      else {
        s(c_idx) match {
          case '[' | '{' | '(' => true & check(s, s(c_idx) :: stack, c_idx + 1, length)
          case ']' | '}' | ')' if stack.isEmpty => false
          case ']' if stack.head == '[' => check(s, stack.tail, c_idx + 1, length) & true
          case '}' if stack.head == '{' => check(s, stack.tail, c_idx + 1, length) & true
          case ')' if stack.head == '(' => check(s, stack.tail, c_idx + 1, length) & true
          case _ => false
        }
      }
    }
    check(s, List(), 0, s.length)
  }
}
