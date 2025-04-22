import java.util.*
import java.io.*
import kotlin.math.max

fun combination(n: Int, k: Int): Long {
    if (k > n) return 0
    val r = if (k > n - k) n - k else k
    var result = 1L
    for (i in 1..r) {
        result = result * (n - r + i) / i
    }
    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val num = br.readLine().split(" ").map{ it.toInt() }
    val sum = MutableList(n) { 0L }
    val rem = MutableList(n) { 0 }
    var count = 1
    var answer = 0L

    sum[0] = num[0].toLong()
    rem[0] = (sum[0] % m).toInt()

    for (i in 1 until n) {
        sum[i] = sum[i - 1] + num[i].toLong()
        rem[i] = (sum[i] % m).toInt()
    }

    rem.sortWith(compareBy<Int> { it })

    for (i in 0 until n - 1) {
        if (rem[i] != rem[i + 1]) {
            if (rem[i] == 0) {
                answer += combination(count + 1, 2)
            } else {
                answer += combination(count, 2)
            }
            count = 1
        } else {
            count++
        }
    }

    if (count != 0) {
        if (rem[n - 1] == 0) {
            answer += combination(count + 1, 2)
        } else {
            answer += combination(count, 2)
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}