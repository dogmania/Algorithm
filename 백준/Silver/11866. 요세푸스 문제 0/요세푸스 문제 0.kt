import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, k) = br.readLine().split(" ").map{ it.toInt() }
    val dq = ArrayDeque<Int>()
    val answer = mutableListOf<Int>()

    dq.addAll((1..n))

    while(dq.isNotEmpty()) {
        var count = 0

        while(count < k) {
            dq.addLast(dq.removeFirst())

            count++
        }

        answer.add(dq.removeLast())
    }

    bw.write("<${answer.joinToString(", ")}>\n")

    bw.flush()
    bw.close()
    br.close()
}