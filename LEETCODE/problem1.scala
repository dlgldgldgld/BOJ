package leetcode.solution

object problem1 {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    import util.control.Breaks.{breakable, break}
    for ( i <- nums.indices; j<- nums.indices ) {
      breakable {
        if ( i == j ) {
          break
        } else {
          if ( nums(i) + nums(j) == target )
            {
              return Array(i, j)
            }
        }
      }
    }
    Array()
  }
}
