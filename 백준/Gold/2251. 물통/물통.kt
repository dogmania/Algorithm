import java.util.*
import java.io.*
import kotlin.math.max

data class Bottle(
    val a: Int,
    val b: Int,
    val c: Int 
)

fun bfs(
    start: Bottle, 
    visited: MutableList<MutableList<MutableList<Boolean>>>, 
    answer: MutableList<Int>,
    A: Int, 
    B: Int,
    C: Int
) {
    val dq = ArrayDeque<Bottle>()
    
    dq.addLast(start)
    visited[start.a][start.b][start.c] = true

    fun tryAdd(newA: Int, newB: Int, newC: Int) {
        if (!visited[newA][newB][newC]) {
            visited[newA][newB][newC] = true
            dq.addLast(Bottle(newA, newB, newC))
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
        
        if (a + b <= A) {
            tryAdd(a + b, 0, c)
        } else {
            tryAdd(A, a + b - A, c)
        }
        
        if (b + c <= C) {
            tryAdd(a, 0, b + c)
        } else {
            tryAdd(a, b + c - C, C)
        }
        
        if (a + c <= A) {
            tryAdd(a + c, b, 0)
        } else {
            tryAdd(A, b, a + c - A)
        }
        
        if (b + c <= B) {
            tryAdd(a, b + c, 0)
        } else {
            tryAdd(a, B, b + c - B)
        }
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val (A, B, C) = br.readLine().split(" ").map{ it.toInt() }
    val visited = MutableList(201) { MutableList(201) { MutableList(201) { false } } }
    val answer = mutableListOf<Int>()

    bfs(Bottle(0, 0, C), visited, answer, A, B, C)

    answer.sortWith(compareBy<Int> { it })
    bw.write(answer.joinToString(" "))

    bw.flush()
    bw.close()
    br.close()
}
