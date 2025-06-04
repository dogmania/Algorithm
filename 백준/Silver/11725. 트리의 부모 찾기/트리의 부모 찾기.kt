import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val graph = Array(N + 1) { mutableListOf<Int>() }
    val parent = Array(N + 1) { -1 }
    val visited = Array(N + 1) { false }

    repeat(N - 1) {
        val (i, o) = br.readLine().split(" ").map { it.toInt() }

        graph[i].add(o)
        graph[o].add(i)
    }

    fun bfs(start: Int) {
        visited[start] = true

        for (node in graph[start]) {
            if (!visited[node]) {
                parent[node] = start
                bfs(node)
            }
        }
    }

    bfs(1)

    for (i in 2..N) {
        bw.write("${parent[i]}\n")
    }

    bw.flush()
    bw.close()
    br.close()
}