object problem14 {
  def longestCommonPrefix(strs: Array[String]): String = {
    val prefixs = strs(0).toArray.map(_.toString).
      scanLeft("")(_ + _).tail
    var prefix_matche = false
    var answer = ""
    for ( prefix <- prefixs ) {
      prefix_matche = true
      for (str <- strs.tail) {
        prefix_matche &= prefix.regionMatches(false, 0, str, 0, prefix.length)
      }
      if (prefix_matche) {
        answer = prefix
      }
    }
    answer
  }
}
