import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (N, K) = br.readLine().split(" ").map{ it.toInt() }
    val visited = Array(100_001) { -1 }
    var time = 0
    var count = 1
    var curMin = Int.MAX_VALUE

    fun bfs() {
        val dq = ArrayDeque<Pair<Int, Int>>()

        dq.addLast(Pair(N, 0))
        visited[N] = 0

        while(dq.isNotEmpty()) {
            val (curNode, curTime) = dq.removeFirst()

            if (curNode == K) {
                if (curTime < curMin) {
                    time = curTime
                    count = 1
                    curMin = curTime
                } else if (curTime == curMin) {
                    count += 1
                }

                continue
            }

            for (next in listOf(curNode - 1, curNode + 1, curNode * 2)) {
                if (next in 0..100_000 && (visited[next] == -1 || visited[next] == curTime + 1)) {
                    dq.addLast(Pair(next, curTime + 1))
                    visited[next] = curTime + 1
                }
            }
        }
    }

    bfs()

    bw.write("${time}\n")
    bw.write("${count}\n")

    bw.flush()
    bw.close()
    br.close()
}