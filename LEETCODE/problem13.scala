object problem13 {
  def romanToInt(s: String): Int = {
    val roman_value = List('M', 'D', 'C', 'L', 'X', 'V', 'I').zip(List(1000, 500, 100, 50, 10, 5, 1)).toMap
    var before_val = 1001
    var answer = 0
    for ( c <- s.toList ) {
      if (before_val >= roman_value(c)) answer += roman_value(c)
      else answer += -2 * before_val + roman_value(c)
      before_val = roman_value(c)
    }
    answer
  }
}
