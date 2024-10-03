class Solution {
    fun solution(s: String): String {
        val list = s.split(' ').map { it.toInt() }
        val sortedList = list.sorted()
        
        return "${sortedList.first()} ${sortedList.last()}"
    }
}