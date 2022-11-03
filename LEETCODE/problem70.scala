object Solution extends App{
  def climbStairs(n: Int): Int = {
    val dp = Array.fill[Int](46)(0)
    dp(1) = 1; dp(2) = 2
    for ( i <- 3 to n ){
      dp(i) = dp(i-2) + dp(i-1)
    }
    dp(n)
  }

  println(climbStairs(45))
}
