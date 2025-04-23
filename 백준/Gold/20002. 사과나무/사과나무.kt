import java.util.*
import java.io.*
import kotlin.math.max

data class Node(
    var x: Int,
    var y: Int
)

fun calRectSum(sum: List<List<Int>>, node1: Node, node2: Node): Int {
    var total = sum[node2.y][node2.x]

    if (node1.x > 0) total -= sum[node2.y][node1.x - 1]
    if (node1.y > 0) total -= sum[node1.y - 1][node2.x]
    if (node1.x > 0 && node1.y > 0) total += sum[node1.y - 1][node1.x - 1]

    return total
}

fun calculateMax(sum: List<List<Int>>, income: List<List<Int>>, width: Int, height: Int): Int {
    var start = Node(0, 0)
    var end = Node(0, 0)
    var maxStart = start
    var maxEnd = end
    var result = -1001

    while(true) {
        if (start.x == width - 1 && start.y == height - 1) {
            result = maxOf(result, income[height - 1][width - 1])
            break
        }

        result = maxOf(result, calRectSum(sum, start, end))

        if (end.x >= width - 1 || end.y >= height - 1) {
            start.x++

            if (start.x > width - 1) {
                start.x = 0
                start.y++
            }

            end = start.copy()
        } else {
            end.x++
            end.y++
        }
    }

    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val income: MutableList<MutableList<Int>> = mutableListOf()
    
    repeat(N) {
        val list = br.readLine().split(" ").map{ it.toInt() }.toMutableList()

        income.add(list)
    }

    val len = income[0].size
    val sum = MutableList(N) { MutableList(len) { 0 } }
    
    for (i in 0 until N) {
        for (j in 0 until len) {
            val cur = income[i][j]
            val up = if (i > 0) sum[i - 1][j] else 0
            val left = if (j > 0) sum[i][j - 1] else 0
            val overlap = if (i > 0 && j > 0) sum[i - 1][j - 1] else 0

            sum[i][j] = cur + up + left - overlap
        }
    }

    val answer = calculateMax(sum.toList(), income.toList(), len, N)

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}