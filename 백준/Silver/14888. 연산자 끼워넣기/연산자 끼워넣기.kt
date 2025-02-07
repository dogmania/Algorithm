import java.util.*

fun dfs(num: List<Int>, mp: MutableMap<Int, Int>, index: Int, answer: MutableList<Int>, v: Int) {
    if (index >= num.size) {
        answer.add(v)
        return
    }

    for (i in 0..3) {
        if (mp[i] != 0) {
            when(i) {
                0 -> {
                    mp[i] = mp[i]!! - 1
                    dfs(num, mp, index + 1, answer, v + num[index])
                    mp[i] = mp[i]!! + 1
                }
                1 -> {
                    mp[i] = mp[i]!! - 1
                    dfs(num, mp, index + 1, answer, v - num[index])
                    mp[i] = mp[i]!! + 1
                }
                2 -> {
                    mp[i] = mp[i]!! - 1
                    dfs(num, mp, index + 1, answer, v * num[index])
                    mp[i] = mp[i]!! + 1
                }
                3 -> {
                    mp[i] = mp[i]!! - 1
                    if (v > 0) {
                        dfs(num, mp, index + 1, answer, v / num[index])
                    } else {
                        val result = (-v) / num[index]
                        dfs(num, mp, index + 1, answer, -result)
                    }
                    mp[i] = mp[i]!! + 1
                }
            }
        }
    }
}

fun main() {
    val n = readln().toInt()
    val num = readln().split(" ").map{ it.toInt() }
    val mp = mutableMapOf<Int, Int>()
    val answer  = mutableListOf<Int>()
    var min = 1000000000
    var max = -1000000000

    readln().split(" ").map{ it.toInt() }.apply {
        mp[0] = this[0]
        mp[1] = this[1]
        mp[2] = this[2]
        mp[3] = this[3]
    }

    dfs(num, mp, 1, answer, num[0])

    for (ans in answer) {
        if (ans > max) max = ans
        if (ans < min) min = ans
    }

    println(max)
    println(min)
}