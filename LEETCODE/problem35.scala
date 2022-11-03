object problem35 extends App{
  def searchInsert(nums: Array[Int], target: Int): Int = {
    def binarySearch(left:Int, right:Int): Int = {
      ( left + right ) / 2 match {
        case _ if left > right => left
        case mid if nums(mid) == target => mid
        case mid if nums(mid) > target => binarySearch(left, mid-1)
        case mid if nums(mid) <= target => binarySearch(mid+1, right)
      }
    }
    binarySearch(0, nums.length-1)
  }
  println(searchInsert(Array(1,2,3,4,5), -1))
}
