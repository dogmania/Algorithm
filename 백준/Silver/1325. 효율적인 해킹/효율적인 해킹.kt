import java.util.*
import java.io.*
import kotlin.math.max

fun bfs(graph: MutableList<MutableList<Int>>, answer: MutableList<Int>, s: Int, n: Int) {
    val dq: ArrayDeque<Int> = ArrayDeque()
    val visited = MutableList(n + 1) { false }

    dq.addLast(s)
    visited[s] = true

    while(dq.isNotEmpty()) {
        val curNode = dq.removeFirst()

        for (g in graph[curNode]) {
            if (!visited[g]) {
                answer[g]++
                dq.addLast(g)
                visited[g] = true
            }
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val graph = MutableList(n + 1) { mutableListOf<Int>() }
    val answer = MutableList(n + 1) { 1 }

    repeat(m) {
        val (s, d) = br.readLine().split(" ").map{ it.toInt() }
        
        graph[s].add(d)
    }

    for(i in 1..n) {
        bfs(graph, answer, i, n)
    }

    val maxValue = answer.maxOf { it }
    for(i in 1..n) {
        if (answer[i] == maxValue) bw.write("$i ")
    }

    bw.newLine()
    bw.flush()
    bw.close()
    br.close()
}