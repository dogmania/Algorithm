import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (A, B) = br.readLine().split(" ").map{ it.toLong() }
    val boundary = Math.sqrt(B.toDouble()).toInt()
    val primeNums = MutableList(boundary + 1) { true }
    var answer = 0

    for (i in 2..boundary) {
        if (primeNums[i]) {
            var j = 2

            while(i * j <= boundary) {
                primeNums[i * j] = false
                j++
            }
        }
    }

    for (i in 2..boundary) {
        if (primeNums[i]) {
            var j = 2

            while(true) {
                val num = Math.pow(i.toDouble(), j.toDouble()).toLong()
                if (num > B) break
                
                if (num in A..B) answer++

                j++
            }
        }
    }

    println(answer)
}