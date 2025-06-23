import java.util.*
import java.io.*
import kotlin.math.*

data class Schedule(
    val start: Int = 0,
    val end: Int = 0
)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val schedules = Array<Schedule>(N) { Schedule() }
    var answer = 0
    var currentStart = 0

    repeat(N) { i ->
        val (s, e) = br.readLine().split(" ").map{ it.toInt() }
        schedules[i] = Schedule(s, e)
    }

    schedules.sortWith(
        compareBy<Schedule> { it.start }
        .thenBy { it.end - it.start }
    )

    for (s in schedules) {
        if (s.start >= currentStart) {
            answer++
            currentStart = s.end
        } else {
            if (s.end < currentStart) {
                currentStart = s.end
            }
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}