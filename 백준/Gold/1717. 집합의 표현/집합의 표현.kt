import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val graph = MutableList(n + 1) { it }
    val answer = mutableListOf<String>()

    fun findParent(node: Int): Int {
        var curNode = node
        
        while(curNode != graph[curNode]) { curNode = graph[curNode] }

        return curNode
    }

    fun setParent(parent: Int, node: Int) {
        if (parent == graph[node]) return

        setParent(parent, graph[node])
        graph[node] = parent
    }

    repeat(m) {
        val (flag, n1, n2) = br.readLine().split(" ").map{ it.toInt() }
        val p1 = findParent(n1)
        val p2 = findParent(n2)

        when(flag) {
            0 -> {
                graph[p2] = p1
            }
            1 -> {
                setParent(p1, n1)
                setParent(p2, n2)

                if (p1 != p2) answer.add("NO")
                else answer.add("YES")
            }
        }
    }

    for (ans in answer) {
        bw.write("${ans}\n")
    }

    bw.flush()
    bw.close()
    br.close()
}