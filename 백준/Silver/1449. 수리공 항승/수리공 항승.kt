import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (N, L) = br.readLine().split(" ").map{ it.toInt() }
    val positions = br.readLine().split(" ").map{ it.toInt() }.toMutableList()
    var answer = 1

    positions.sortWith(compareBy<Int> { it })

    var curStart = positions[0]
    for (p in positions) {
        if (p - curStart + 1 > L) {
            curStart = p
            answer++
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}