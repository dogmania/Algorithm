class Solution {
    fun solution(s: String): String {
        var answer = ""
        var isFirst = true
        
        for (i in 0 until s.length) {
            when {
                s[i].isUpperCase() -> {
                    if (!isFirst) answer += s[i].lowercaseChar()
                    else  {
                        answer += s[i]
                        isFirst = false
                    }
                }
                s[i].isLowerCase() -> {
                    if (isFirst) {
                        answer += s[i].uppercaseChar()
                        isFirst = false
                    } else answer += s[i]
                }
                s[i] == ' ' -> {
                    answer += s[i]
                    isFirst = true
                }
                else -> {
                    answer += s[i]
                    isFirst = false
                }
            }
        }
        
        return answer
    }
}