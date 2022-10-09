object problem66 extends App{
  def plusOne(digits: Array[Int]): Array[Int] = {
    def helper(idx:Int, a:Int=0): List[Int] = {
      if (idx == -1) {
        if ( a == 1 ) return List(1)
        else return Nil
      }
      if ( digits(idx) + a >= 10 ) {
        helper(idx-1, 1) ::: List((digits(idx) + a) % 10)
      }
      else{
        helper(idx-1) ::: List((digits(idx) + a) % 10)
      }
    }
    helper(digits.length-1, 1).toArray
  }

  plusOne(Array(1,2,3,9)) foreach print
  println()
  plusOne(Array(9)) foreach print
  println()
  plusOne(Array(9,9)) foreach print
}
