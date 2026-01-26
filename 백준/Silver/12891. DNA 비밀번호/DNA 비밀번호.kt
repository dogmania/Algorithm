import java.io.*
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (s, p) = br.readLine().split(" ").map{ it.toInt() }
    val dna = br.readLine()
    val condition = IntArray(4) // 0: A, 1: C, 2: G, 3: T
    var answer = 0
    val mp = mutableMapOf<String, Int>()
    var current = IntArray(4) // 0: A, 1: C, 2: G, 3: T

    val input = br.readLine()
    val st = StringTokenizer(input)

    repeat(4) { i ->
        condition[i] = st.nextToken().toInt()
    }

    fun add(c: Char) {
        when(c) {
            'A' -> current[0] += 1
            'C' -> current[1] += 1
            'G' -> current[2] += 1
            'T' -> current[3] += 1
            else -> return
        }
    }

    fun remove(c: Char) {
        when(c) {
            'A' -> current[0] -= 1
            'C' -> current[1] -= 1
            'G' -> current[2] -= 1
            'T' -> current[3] -= 1
            else -> return
        }
    }

    fun check() {
        if (
            current[0] >= condition[0] &&
            current[1] >= condition[1] &&
            current[2] >= condition[2] &&
            current[3] >= condition[3]
        ) answer++
    }

    for (i in 0 until p) {
        add(dna[i])
    }

    check()

    for (i in 1..(s - p)) {
        remove(dna[i - 1])
        add(dna[i + p - 1])
        check()
    }

    bw.write("$answer\n")
  
    bw.flush()
}

