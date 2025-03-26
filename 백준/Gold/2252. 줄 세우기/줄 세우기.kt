import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val answer = mutableListOf<Int>()
    val graph = MutableList(n + 1) { mutableListOf<Int>() }
    val degree = MutableList(n + 1) { 0 }
    val visited = MutableList(n + 1) { false }
    val dq = ArrayDeque<Int>()

    repeat(m) {
        val (s, d) = br.readLine().split(" ").map{ it.toInt() }

        graph[s].add(d)
        degree[d]++
    }

    for (i in 1..n) { dq.addLast(i) }

    while(dq.isNotEmpty()) {
        val curNode = dq.removeFirst()

        if (degree[curNode] != 0 || visited[curNode]) {
            dq.addLast(curNode)
            continue
        }

        answer.add(curNode)
        visited[curNode] = true

        for (g in graph[curNode]) {
            degree[g]--
        }
    }

    for (ans in answer) {
        bw.write("${ans} ")
    }

    bw.flush()
    bw.close()
    br.close()
}