object problem88 extends App{
  import Array.concat
  def merge(nums1: Array[Int], m:Int, nums2:Array[Int], n:Int):Unit = {
    for (i <- m until m+n) {
      nums1(i) = nums2(i-m)
    }
    for (a <- nums1.sorted.zipWithIndex) {
      nums1(a._2) = a._1
    }
  }

  merge(nums1 = Array(1,2,3,0,0,0), m = 3, nums2 = Array(2,5,6), n = 3)
}
