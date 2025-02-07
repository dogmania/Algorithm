import java.util.*

fun main() {
    val (n, m) = readln().split(" ").map{ it.toInt() }
    val num = readln().split(" ").map{ it.toInt() }.toMutableList()
    val sum = (1..n).toMutableList()
    var start = 0
    var end = 0
    var answer = 0
    var curSum = 0

    sum[0] = num[0]
    for (i in 1 until n) {
        sum[i] = num[i] + sum[i - 1]
    }

    while(end < n && start <= end) {
        when {
            sum[end] - sum[start] + num[start] == m -> {
                answer += 1
                end += 1
            }
            sum[end] - sum[start] + num[start] > m -> {
                if (start == end) {
                    start += 1
                    end += 1
                } else {
                    start += 1
                }
            }
            sum[end] - sum[start] + num[start] < m -> {
                end += 1
            }
        }
    }

    println(answer)
}