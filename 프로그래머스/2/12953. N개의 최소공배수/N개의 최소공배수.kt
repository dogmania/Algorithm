class Solution {
    fun solution(arr: IntArray): Int {
        var answer = 0
        var i = 1
        var p = true
        
        while(true) {
            p = true
            answer = arr.last() * i
            
            for (item in arr) {
                if (answer % item != 0) {
                    p = false
                    break;
                }
            }
            
            if (p) break;
            
            i += 1
        }
        
        return answer
    }
}