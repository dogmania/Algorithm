class Solution {
    fun solution(s: String): IntArray {
        var str = s
        var answer = mutableListOf<Int>()
        var count = 0
        var zeroCount = 0
        
        while(str != "1") {
            var result = removeZero(str)
            
            str = toBinary(result.first)
            zeroCount += result.second
            count += 1
        }
        
        answer.add(count)
        answer.add(zeroCount)
        
        return answer.toIntArray()
    }
    
    fun removeZero(s: String): Pair<String, Int> {
        var result = ""
        var zeroCount = 0
        
        for (i in 0 until s.length) {
            if (s[i] == '1') result += s[i]
            else zeroCount += 1
        }
        
        return Pair(result, zeroCount)
    }
    
    fun toBinary(s: String): String {
        var result = ""
        var num = s.length
        
        while(num != 1) {
            result += (num % 2).toString()
            num /= 2
        }
        
        result += '1'
        
        return result.reversed()
    }
}