class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = IntArray(2)
        var loop = true
        
        if (isPerfectSquare(yellow)) {
            answer[0] = yellow + 2
            answer[1] = yellow + 2
        } else {            
            while(loop) {
                for (i in yellow downTo 2) {
                    if (yellow % i != 0) continue
                    
                    val width = i
                    val height = yellow / i
                    
                    if ((width + 2) * (height + 2) == brown + yellow) {
                        answer[0] = width + 2
                        answer[1] = height + 2
                        loop = false
                        break
                    }
                }
            }
        }
        
        return answer
    }
    
    fun isPerfectSquare(n: Int): Boolean {
        val sqrt = Math.sqrt(n.toDouble())
        return n.toDouble() == sqrt.toInt().toDouble()
    }
}