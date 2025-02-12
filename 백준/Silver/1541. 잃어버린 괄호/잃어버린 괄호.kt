import java.util.*

fun sum(str: String, s: Int, e: Int): Int {
    var result = 0
    val list = str.slice(s..e).split("+").map{ it.toInt() }

    for (l in list) {
        result += l
    }

    return result
}

fun main() {
    val s = readLine()!!
    val len = s.length
    val minus = ArrayDeque<Int>()
    var start = 0
    var end = 0
    var answer = 0

    while(true) {
        if (end == len - 1) {
            if (start == 0) answer += sum(s, start, end)
            else answer -= sum(s, start, end)
            break
        }

        if (s[end] == '-') {
            if (start == 0) answer += sum(s, start, end - 1)
            else answer -= sum(s, start, end - 1)
            start = end + 1
            end = start
            continue
        }

        end += 1
    }

    println(answer)
}