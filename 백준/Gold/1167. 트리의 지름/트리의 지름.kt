import java.util.*
import java.io.*
import kotlin.math.max

fun bfs(graph: MutableList<MutableList<Pair<Int, Int>>>, start: Int, v: Int): Pair<Int, Int> {
    val dq: ArrayDeque<Pair<Int, Int>> = ArrayDeque()
    val visited = MutableList(v + 1) { false }
    var maxDistance = 0
    var maxNode = start

    dq.addLast(Pair(start, 0))
    visited[start] = true

    while(dq.isNotEmpty()) {
        val (curNode, curDistance) = dq.removeFirst()
        
        if (maxDistance < curDistance) {
            maxDistance = curDistance
            maxNode = curNode
        }

        for (node in graph[curNode]) {
            if (!visited[node.first]) {
                dq.addLast(Pair(node.first, curDistance + node.second))
                visited[node.first] = true
            }
        }
    }

    return Pair(maxNode, maxDistance)
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val v = br.readLine().toInt()
    val graph = MutableList(v + 1) { mutableListOf<Pair<Int, Int>>() }

    repeat(v) {
        val st = StringTokenizer(br.readLine())
        val start = st.nextToken().toInt()

        while(st.hasMoreTokens()) {
            val next = st.nextToken().toInt()
            if (next == -1) break
            val distance = st.nextToken().toInt()

            graph[start].add(Pair(next, distance))
        }
    }

    val maxNode = bfs(graph, 1, v).first
    val answer = bfs(graph, maxNode, v).second

    println(answer)
}