object problem3 extends App{
  def lengthOfLongestSubstring(s: String): Int = {
    s.foldLeft((List[Char](), 0)){
      case (acc, v) =>
        val f = acc._1.indexOf(v)
        if ( f != -1 ){
          (acc._1.slice(f+1, acc._1.length) :+ v, acc._2)
        } else {
          (acc._1 :+ v, math.max(acc._2, 1 + acc._1.length))
        }
    }._2
  }
  lengthOfLongestSubstring("abcabcbb")
}
