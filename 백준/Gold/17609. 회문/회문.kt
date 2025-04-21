import java.util.*
import java.io.*
import kotlin.math.max

fun isPalindrom(s: String, left: Int, right: Int, count: Int): Int {
    var l = left
    var r = right

    while(l < r) {
        if (s[l] == s[r]) {
            l++
            r--
        } else {
            if (count == 1) return 2

            val result1 = isPalindrom(s, l + 1, r, count + 1)
            val result2 = isPalindrom(s, l, r - 1, count + 1)

            return minOf(result1, result2)
        }
    }

    return count
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val t = br.readLine().toInt()
    val testCase = mutableListOf<String>()
    val answer = mutableListOf<Int>()

    repeat(t) {
        testCase.add(br.readLine())
    }

    for (tc in testCase) {
        answer.add(isPalindrom(tc, 0, tc.length - 1, 0))
    }

    bw.write(answer.joinToString("\n"))

    bw.flush()
    bw.close()
    br.close()
}