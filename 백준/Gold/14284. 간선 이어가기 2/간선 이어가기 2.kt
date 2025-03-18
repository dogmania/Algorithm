import java.util.*
import java.io.*
import kotlin.math.max

data class Node(val node: Int, val weight: Int): Comparable<Node> {
    override fun compareTo(other: Node): Int = this.weight - other.weight
}

fun dijkstra(
    graph: MutableList<MutableList<Node>>,
    s: Int,
    t: Int,
    n: Int
): Int {
    val pq = PriorityQueue<Node>()
    val distance = MutableList(n + 1) { Int.MAX_VALUE }

    distance[s] = 0
    pq.add(Node(s, 0))

    while(pq.isNotEmpty()) {
        val (curNode, curWeight) = pq.poll()

        if (curWeight > distance[curNode]) continue

        for ((nextNode, nextWeight) in graph[curNode]) {
            val newWeight = curWeight + nextWeight

            if (newWeight < distance[nextNode]) {
                distance[nextNode] = newWeight
                pq.add(Node(nextNode, newWeight))
            }
        }
    }

    return distance[t]
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val graph = MutableList(n + 1) { mutableListOf<Node>() }

    repeat(m) {
        val (a, b, c) = br.readLine().split(" ").map{ it.toInt() }

        graph[a].add(Node(b, c))
        graph[b].add(Node(a, c))
    }

    val (s, t) = br.readLine().split(" ").map{ it.toInt() }

    val answer = dijkstra(graph, s, t, n)

    bw.write("$answer\n")

    bw.flush()
    bw.close()
    br.close()
}