import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val N = br.readLine().toInt()
    val graph: Array<Array<Char>> = Array(N) { Array(N) { ' ' } }
    var answer = 0

    repeat(N) { i ->
        val input = br.readLine()

        for (j in 0 until N) {
            graph[i][j] = input[j]
        }
    }

    // 행 기준으로 연속된 두 값 바꾸기
    fun swapRow(i: Int, a: Int, b: Int) {
        val tmp = graph[i][a]
        graph[i][a] = graph[i][b]
        graph[i][b] = tmp
    }

    // 열 기준으로 연속된 두 값 바꾸기
    fun swapColumn(j: Int, a: Int, b: Int) {
        val tmp = graph[a][j]
        graph[a][j] = graph[b][j]
        graph[b][j] = tmp
    }

    // 행 기준으로 개수 세기
    fun countRow(i: Int): Int {
        var max = 0
        var current = 1

        for (j in 1 until N) {
            if (graph[i][j - 1] == graph[i][j]) current++
            else {
                max = maxOf(max, current)
                current = 1
            }
        }

        return maxOf(max, current)
    }

    // 열 기준으로 개수 세기
    fun countColumn(j: Int): Int {
        var max = 0
        var current = 1

        for (i in 1 until N) {
            if (graph[i - 1][j] == graph[i][j]) current++
            else {
                max = maxOf(max, current)
                current = 1
            }
        }

        return maxOf(max, current)
    }

    // 초기 데이터 기반 최댓값 찾기
    for (i in 0 until N) {
        answer = maxOf(answer, countRow(i), countColumn(i))
    }

    // 행 기준으로 바꿔가며 최댓값 찾기
    for (i in 0 until N) {
        for (j in 0 until N - 1) {
            if (graph[i][j] != graph[i][j + 1]) {
                swapRow(i, j, j + 1)
                answer = maxOf(answer, countRow(i), countColumn(j), countColumn(j + 1))
                swapRow(i, j, j + 1)
            }
        }
    }

    // 열 기준으로 바꿔가며 최댓값 찾기
    for (j in 0 until N) {
        for (i in 0 until N - 1) {
            if (graph[i][j] != graph[i + 1][j]) {
                swapColumn(j, i, i + 1)
                answer = maxOf(answer, countRow(i), countRow(i + 1), countColumn(j))
                swapColumn(j, i, i + 1)
            }
        }
    }

    bw.write("${answer}\n")

    bw.flush()
    bw.close()
    br.close()
}