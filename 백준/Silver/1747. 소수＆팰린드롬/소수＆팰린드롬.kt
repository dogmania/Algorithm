import java.util.*
import java.io.*
import kotlin.math.max

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val primeNums = MutableList(1000001) { true }
    var answer = 0

    primeNums[1] = false

    for (i in 2..1000000) {
        if (primeNums[i]) {
            var j = 2

            while(i * j <= 1000000) {
                primeNums[i * j] = false
                j++
            }
        }
    }

    for (i in n..1000000) {
        if (primeNums[i]) {
            val reversedNum = i.toString().reversed().toInt()

            if (i == reversedNum) {
                answer = i
                break
            }
        }
    }

    if (answer == 0) println(1003001)
    else println(answer)
}