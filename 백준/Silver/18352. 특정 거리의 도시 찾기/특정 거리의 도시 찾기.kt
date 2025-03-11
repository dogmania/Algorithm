import java.util.*
import java.io.*
import kotlin.math.max

fun bfs(graph: MutableList<MutableList<Int>>, distance: MutableList<Int>, n: Int, k: Int, s: Int) {
    val dq: ArrayDeque<Pair<Int, Int>> = ArrayDeque()
    val visited = MutableList(n + 1) { false }

    dq.addLast(Pair(s, 0))
    visited[s] = true

    while(dq.isNotEmpty()) {
        val (curNode, curDistance) = dq.removeFirst()
        
        if (distance[curNode] != -1 && distance[curNode] > curDistance) distance[curNode] = curDistance

        if (distance[curNode] == -1) distance[curNode] = curDistance

        for (g in graph[curNode]) {
            if (!visited[g]) {
                visited[g] = true
                dq.addLast(Pair(g, curDistance + 1))
            }
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, k, x) = br.readLine().split(" ").map{ it.toInt() }
    val graph = MutableList(n + 1) { mutableListOf<Int>() }
    val distance = MutableList(n + 1) { -1 }
    val answer = mutableListOf<Int>()

    repeat(m) {
        val (s, d) = br.readLine().split(" ").map{ it.toInt() }

        graph[s].add(d)
    }

    bfs(graph, distance, n, k, x)

    for (i in 1..n) {
        if (distance[i] == k) {
            answer.add(i)
        }
    }

    if (answer.size == 0) println(-1)
    else {
        val sortedList = answer.sorted()

        for (ans in sortedList) {
            println(ans)
        }
    }
}