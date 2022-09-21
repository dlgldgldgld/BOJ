object problem9 {
  def isPalindrome(x: Int): Boolean = {
    val l = x.toString
    val r = x.toString
    for (i <- 0 until l.length) {
      if (l(i) != r(l.length - (i+1))) {
        return false
      }
    }
    true
  }
}
