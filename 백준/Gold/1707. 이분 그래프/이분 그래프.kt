import java.util.*
import java.io.*
import kotlin.math.max

fun bfs(graph: MutableList<MutableList<Int>>, group: MutableList<Int>, start: Int): Boolean {
    val dq = ArrayDeque<Int>()

    dq.addLast(start)
    group[start] = 0
    
    while(dq.isNotEmpty()) {
        val curNode = dq.removeFirst()

        for (node in graph[curNode]) {
            if (group[node] == -1) {
                group[node] = (group[curNode] + 1) % 2
                dq.addLast(node)
            } else if (group[node] == group[curNode]) return false
        }
    }

    return true
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val k = br.readLine().toInt()
    val answer = mutableListOf<String>()

    repeat(k) {
        val (v, e) = br.readLine().split(" ").map{ it.toInt() }
        val graph = MutableList(v + 1) { mutableListOf<Int>() }
        val group = MutableList(v + 1) { -1 }
        var isYes = true

        repeat(e) {
            val (u, v) = br.readLine().split(" ").map{ it.toInt() }

            graph[u].add(v)
            graph[v].add(u)
        }

        for (i in 1..v) {
            if (group[i] == -1) {
                if (!bfs(graph, group, i)) {
                    isYes = false
                    break 
                }
            }
        }

        answer.add(if (isYes) "YES" else "NO")
    }

    bw.write(answer.joinToString("\n"))
    bw.write("\n")
    bw.flush()
    bw.close()
    br.close()
}