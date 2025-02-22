import java.util.*
import java.io.*

fun isPrime(num: Int, primeNum: MutableList<Int>): Boolean {
    if (num < 2) return false
    for (p in primeNum) {
        if (p * p > num) break
        if (num % p == 0) return false
    }
    return true
}

fun dfs(answer: MutableList<Int>, primeNum: MutableList<Int>, curNum: Int, length: Int, n: Int) {
    if (length == n) {
        answer.add(curNum)
        return
    }

    for (i in 1..9) {
        val nextNum = curNum * 10 + i

        if (isPrime(nextNum, primeNum)) dfs(answer, primeNum, nextNum, length + 1, n)
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val primeNum = mutableListOf<Int>()
    val answer = mutableListOf<Int>()

    for (i in 2..9999) {
        if (isPrime(i, primeNum)) primeNum.add(i)
    }

    for (i in listOf(2, 3, 5, 7)) {
        dfs(answer, primeNum, i, 1, n)
    }

    answer.sort()

    val sb = StringBuilder()
    for (ans in answer) {
        sb.append(ans).append("\n")
    }

    bw.write(sb.toString())
    bw.flush()
    bw.close()
}