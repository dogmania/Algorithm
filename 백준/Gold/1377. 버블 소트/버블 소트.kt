import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val num = MutableList(n) { readLine()!!.toInt() }
    val newList = num.sorted()
    var answer  = 0
    val originalIndex = mutableMapOf<Int, Int>()
    val sortedIndex = mutableMapOf<Int, Int>()

    for (i in 0 until n) {
        originalIndex[num[i]] = i
    }

    for (i in 0 until n) {
        sortedIndex[newList[i]] = i
    }

    for (i in 0 until n) {
        answer = maxOf(answer, originalIndex[num[i]]!! - sortedIndex[num[i]]!!)
    }

    println(answer + 1)
}