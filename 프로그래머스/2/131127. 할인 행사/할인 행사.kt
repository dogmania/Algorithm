class Solution {
    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int {
        var answer: Int = 0
        var maxIndex = discount.size - 10
        var isPossible = true
        
        for (i in 0..maxIndex) {
            isPossible = true
            val map = mutableMapOf<String, Int>()
            
            for (j in i..i + 9) {
                map[discount[j]] = map.getOrDefault(discount[j], 0) + 1
            }
            
            for (i in 0 until want.size) {
                if (map.getOrDefault(want[i], 0) < number[i]) {
                    isPossible = false
                    break
                }
            }
            
            if (isPossible) answer += 1
        }
        
        return answer
    }
}