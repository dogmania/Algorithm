import java.util.*
import java.io.*

fun merge(num: MutableList<Int>, sorted: MutableList<Int>, s: Int, e: Int, m: Int) {
    var (i, j, k) = listOf(s, m + 1, s)

    while (i <= m && j <= e) {
        if (num[i] > num[j]) {
            sorted[k] = num[j]
            j++
        } else {
            sorted[k] = num[i]
            i++
        }
        k++
    }

    while (i <= m) {
        sorted[k] = num[i]
        k++
        i++
    }

    while (j <= e) {
        sorted[k] = num[j]
        k++
        j++
    }

    for (t in s..e) {
        num[t] = sorted[t]
    }
}

fun mergeSort(num: MutableList<Int>, sorted: MutableList<Int>, s: Int, e: Int) {
    if (s < e) {
        val mid = (s + e) / 2
        mergeSort(num, sorted, s, mid)
        mergeSort(num, sorted, mid + 1, e)
        merge(num, sorted, s, e, mid)
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val num = mutableListOf<Int>()
    val sorted = MutableList(n) { 0 }

    for (i in 0 until n) {
        val input = br.readLine().toInt()
        num.add(input)
    }

    mergeSort(num, sorted, 0, n - 1)

    val output = StringBuilder()
    for (ans in num) {
        output.append("$ans\n")
    }
    print(output)
}