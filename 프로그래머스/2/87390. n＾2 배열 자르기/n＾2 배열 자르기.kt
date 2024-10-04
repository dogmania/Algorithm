class Solution {
    fun solution(n: Int, left: Long, right: Long): IntArray {
        var answer = mutableListOf<Int>()
        
        for(i in left..right) {
            val x = (i % n).toInt()
            val y = (i / n).toInt()
            
            answer.add(maxOf(x, y) + 1)
        }
        
        return answer.toIntArray()
    }
}