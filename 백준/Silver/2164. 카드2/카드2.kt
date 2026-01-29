import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val dq = ArrayDeque<Int>()

    for (i in 1..n) {
        dq.addLast(i)
    }

    while(dq.size >= 3) {
        dq.removeFirst()
        dq.addLast(dq.removeFirst())
    }

    if (dq.size == 2) bw.write("${dq.removeLast()}\n")
    else bw.write("${dq.removeFirst()}\n")
  
    bw.flush()
}

