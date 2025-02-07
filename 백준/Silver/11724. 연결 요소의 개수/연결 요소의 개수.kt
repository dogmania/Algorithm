import java.util.*

fun bfs(graph: MutableList<MutableList<Int>>, visited: MutableList<Boolean>, start: Int) {
    val dq: ArrayDeque<Int> = ArrayDeque()

    dq.addLast(start)
    visited[start] = true

    while(dq.isNotEmpty()) {
        val currentNode = dq.removeFirst()

        for (node in graph[currentNode]) {
            if (!visited[node]) {
                dq.addLast(node)
                visited[node] = true
            }
        }
    }
}

fun main() {
    val (n, m) = readln().split(" ").map{ it.toInt() }
    val graph = MutableList(n + 1) { mutableListOf<Int>() }
    val visited = MutableList(n + 1) { false }
    var answer = 0

    repeat(m) {
        val (start, destination) = readln().split(" ").map{ it.toInt() }
        graph[start].add(destination)
        graph[destination].add(start)
    }

    for (i in 1..n) {
        if (!visited[i]) {
            bfs(graph, visited, i)
            answer += 1
        }
    }

    println(answer)
}