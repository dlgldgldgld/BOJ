object problem26 extends App{
  def removeDuplicates(nums: Array[Int]): Int = {
    val b = nums.distinct
    for (i <- b.length until nums.length) {
      nums(b.length-1) = nums(b.length)
    }
    for (i <- 0 until b.length) {
      nums(i) = b(i)
    }
    nums.distinct.length
  }
  removeDuplicates(Array(1,1,2))
}
