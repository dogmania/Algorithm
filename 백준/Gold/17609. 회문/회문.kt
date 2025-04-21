import java.util.*
import java.io.*
import kotlin.math.max

fun isPalindrome(s: String): Int {
    var l = 0
    var r = s.length - 1

    while(l < r) {
        if (s[l] == s[r]) {
            l++
            r--
        } else {
            if (isStrictPalindrome(s, l + 1, r) || isStrictPalindrome(s, l, r - 1)) {
                return 1
            } else {
                return 2
            }
        }
    }

    return 0
}

fun isStrictPalindrome(s: String, left: Int, right: Int): Boolean {
    var l = left
    var r = right

    while(l < r) {
        if (s[l] == s[r]) {
            l++
            r--
        } else {
            return false
        }
    }

    return true
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
        answer.add(isPalindrome(tc))
    }

    bw.write(answer.joinToString("\n"))

    bw.flush()
    bw.close()
    br.close()
}