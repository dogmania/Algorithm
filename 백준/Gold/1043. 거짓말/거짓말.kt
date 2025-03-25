import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val people = br.readLine().split(" ").map{ it.toInt() }  // 진실을 아는 사람에 대한 입력
    val parent = MutableList(n + 1) { it }
    val party = MutableList(m) { mutableListOf<Int>() }
    var answer = m

    fun findParent(node: Int): Int {
        if (node != parent[node]) parent[node] = findParent(parent[node])
        
        return parent[node]
    }

    fun union(node1: Int, node2: Int) {
        val p1 = findParent(node1)
        val p2 = findParent(node2)

        if (p1 != p2) parent[p2] = p1
    }

    // party에 대한 정보
    for (i in 0 until m) {
        val input = br.readLine().split(" ").map{ it.toInt() }

        for (j in 1 until input.size) {
            party[i].add(input[j])
        }
    }

    for (p in party) {
        val first = p[0]

        for (i in 1 until p.size) {
            union(first, p[i])
        }
    }

    for (p in party) {
        for (i in 1 until people.size) {
            if (findParent(p[0]) == findParent(people[i])) {
                answer--
                break
            }
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}
