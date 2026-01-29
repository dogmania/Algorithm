import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val pq = PriorityQueue<Int>(compareBy<Int> { abs(it) }.thenBy { it })

    for (i in 0 until n) {
        val input = br.readLine().toInt()

        if (input != 0) pq.add(input)
        else {
            if (pq.isNotEmpty()) bw.write("${pq.poll()}\n")
            else {
                bw.write("0\n")
            }
        }
    }
  
    bw.flush()
}