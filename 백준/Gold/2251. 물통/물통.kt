import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (A, B, C) = br.readLine().split(" ").map{ it.toInt() }
    val visited = Array(201) { Array(201) { BooleanArray(201) { false } } }
    val answer = mutableSetOf<Int>()

    fun bfs() {
        val dq = ArrayDeque<Triple<Int, Int, Int>>()

        dq.addLast(Triple(0, 0, C))
        visited[0][0][C] = true

        fun tryAdd(newA: Int, newB: Int, newC: Int) {
            if (!visited[newA][newB][newC]) {
                dq.addLast(Triple(newA, newB, newC))
                visited[newA][newB][newC] = true
            }
        }

        while(dq.isNotEmpty()) {
            val (a, b, c) = dq.removeFirst()

            if (a == 0) answer.add(c)

            if (a + b <= B) {
                tryAdd(0, a + b, c)
            } else {
                tryAdd(a + b - B, B, c)
            }

            if (a + c <= C) {
                tryAdd(0, b, a + c)
            } else {
                tryAdd(a + c - C, b, C)
            }

            if (b + a <= A) {
                tryAdd(b + a, 0, c)
            } else {
                tryAdd(A, b + a - A, c)
            }

            if (b + c <= C) {
                tryAdd(a, 0, b + c)
            } else {
                tryAdd(a, b + c - C, C)
            }

            if (c + a <= A) {
                tryAdd(c + a, b, 0)
            } else {
                tryAdd(A, b, c + a - A)
            }

            if (c + b <= B) {
                tryAdd(a, c + b, 0)
            } else {
                tryAdd(a, B, c + b - B)
            }
        }
    }

    bfs()

    bw.write(answer.toMutableList().sorted().joinToString(" ") + "\n")

    bw.flush()
    bw.close()
    br.close()
}
