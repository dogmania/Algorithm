import java.util.*
import java.io.*
import kotlin.math.max

fun binarySearch(arr: List<Int>, s: Int, e: Int, M: Int): Int {
    var result = 0
    var start = s
    var end = e

    while (start <= end) {
        val mid = (start + end) / 2
        var sum = 0
        var count = 1

        for (num in arr) {
            sum += num

            if (sum > mid) {
                count++
                sum = num
            }
        }

        if (count <= M) {
            result = mid
            end = mid - 1
        } else {
            start = mid + 1
        }
    }

    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M) = br.readLine().split(" ").map{ it.toInt() }
    val lecture = br.readLine().split(" ").map{ it.toInt() }
    var sum = 0
    var max = 0
    
    for (l in lecture) {
        sum += l
        if (l > max) max = l
    }

    val answer = binarySearch(lecture, max, sum, M)

    println(answer)
}