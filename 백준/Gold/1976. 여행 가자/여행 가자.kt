import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val M = br.readLine().toInt()
    val parent = IntArray(N + 1) { it }
    var answer = "YES"

    fun findParent(node: Int): Int {
        if (node != parent[node]) parent[node] = findParent(parent[node])

        return parent[node]
    }

    fun union(n1: Int, n2: Int) {
        val p1 = findParent(n1)
        val p2 = findParent(n2)

        if (p1 != p2) parent[p2] = p1
    }

    for (i in 1..N) {
        val input = br.readLine().split(" ").map{ it.toInt() }

        for (j in 0 until input.size) {
            if (input[j] == 1) {
                union(i, j + 1)
            }
        }
    }

    val route = br.readLine().split(" ").map{ it.toInt() }
    val first = route[0]

    for (r in route) {
        if (findParent(first) != findParent(r)) {
            answer = "NO"
            break
        }
    }

    bw.write(answer + "\n")

    bw.flush()
    bw.close()
    br.close()
}