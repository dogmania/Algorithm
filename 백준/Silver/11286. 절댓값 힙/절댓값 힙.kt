import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val pq = PriorityQueue<Int>() { a, b ->
        if (abs(a) == abs(b)) a - b else abs(a) - abs(b)
    }
    val N = br.readLine().toInt()
    val answer = mutableListOf<Int>()

    repeat(N) {
        val input = br.readLine().toInt()

        if (input == 0) {
            if (pq.isEmpty()) answer.add(0) else answer.add(pq.poll())
        } else {
            pq.add(input)
        }
    }

    bw.write("${answer.joinToString("\n")}\n")

    bw.flush()
    bw.close()
    br.close()
}