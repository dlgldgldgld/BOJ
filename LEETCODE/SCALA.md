# SCALA TIPS

## Array 할당
```scala
val dp = Array.fill[Int](46)(0)
```

## ListNode debug code
```scala
class ListNode(_x: Int = 0, _next: ListNode = null) {
  var next: ListNode = _next
  var x: Int = _x

  def printListNode(head: ListNode = this): Unit = {
    if (head == null) return
    println(head.x)
    printListNode(head.next)
  }
}
```
