import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val pq = PriorityQueue<Int>()
    var answer = -1

    repeat(N) {
        val input = br.readLine().split(" ").map{ it.toInt() }

        for (i in input) {
            pq.add(-i)
        }
    }

    repeat(N) {
        answer = pq.poll() * (-1)
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}