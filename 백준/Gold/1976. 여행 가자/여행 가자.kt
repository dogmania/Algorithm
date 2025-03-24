import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val graph: MutableList<MutableList<Int>> = mutableListOf()
    val parent = MutableList(n) { it }
    var answer = "YES"

    repeat(n) {
        val input = br.readLine().split(" ").map{ it.toInt() }.toMutableList()

        graph.add(input)
    }

    fun findParent(node: Int): Int {
        if (node != parent[node]) {
            parent[node] = findParent(parent[node])
        }

        return parent[node]
    }

    fun union(n1: Int, n2: Int) {
        val p1 = findParent(n1)
        val p2 = findParent(n2)

        if (p1 != p2) parent[p2] = p1
    }

    for (i in 0 until n) {
        for (j in 0 until n) {
            if (graph[i][j] == 1) {
                union(i, j)
            }
        }
    }

    val plan = br.readLine().split(" ").map{ it.toInt() - 1 }

    for (i in 0 until plan.size - 1) {
        if (findParent(plan[i]) != findParent(plan[i + 1])) {
            answer = "NO"
            break
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}