import java.util.*

val answer: MutableList<MutableList<Int>> = mutableListOf()

fun dfs(num: MutableList<Int>, list: MutableList<Int>, index: Int, size: Int) {
    if (index >= num.size) return

    val currentList = list.toMutableList()

    if (currentList.size == size) {
        answer.add(currentList) 
        return
    }

    currentList.add(num[index])

    dfs(num, currentList, index, size)
    dfs(num, list, index + 1, size)
}

fun main() {
    val (n, m) = readln().split(" ").map{ it.toInt() }
    val num = (1..n).toMutableList()

    for (i in 0 until n) {
        val list = mutableListOf<Int>()
        list.add(num[i])
        dfs(num, list, i, m)
    } 

    for (ans in answer) {
        for (a in ans) {
            print("$a ")
        }

        println()
    }
}