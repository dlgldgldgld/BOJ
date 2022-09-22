object problem771 {
    def numJewelsInStones(jewels: String, stones: String): Int = {
        var ans = 0
        jewels.foreach( a => {
            ans += stones.count(s => s == a) 
        })
        ans
    }
}
