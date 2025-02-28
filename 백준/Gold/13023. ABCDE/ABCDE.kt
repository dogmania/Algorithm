import java.util.*
import java.io.*

fun dfs(graph: MutableList<MutableList<Int>>, visited: MutableList<Boolean>, curNode: Int, curCount: Int, answer: MutableList<Int>) {
    if (answer[0] == 1) return
    if (curCount == 4) {
        answer[0] = 1
        return
    }

    visited[curNode] = true

    for (g in graph[curNode]) {
        if (!visited[g]) {
            dfs(graph, visited, g, curCount + 1, answer)
            if (answer[0] == 1) return
        }
    }

    visited[curNode] = false
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val graph = MutableList(n) { mutableListOf<Int>() }
    val visited = MutableList(n) { false }
    val answer = mutableListOf<Int>(0)

    repeat(m) {
        val (s, d) = br.readLine().split(" ").map{ it.toInt() }

        graph[s].add(d)
        graph[d].add(s)
    }

    for (i in 0 until n) {
        dfs(graph, visited, i, 0, answer)
        if (answer[0] == 1) {
            println(1)
            return
        }
    }

    println(0)
}