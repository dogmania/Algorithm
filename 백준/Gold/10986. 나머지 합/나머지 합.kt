import java.io.*

fun combination(n: Int, k: Int): Long {
    if (k > n) return 0L

    val r = if (n - k < k) n - k else k
    var result = 1L

    for (i in 1..r) {
        result = result * (n - r + i) / i
    }

    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val (n, m) = br.readLine().split(" ").map{ it.toInt() }
    val numbers = br.readLine().split(" ").map{ it.toInt() }
    val rem = MutableList(n) { 0 }
    var answer = 0L

    rem[0] = numbers[0] % m

    for (i in 1 until n) {
        rem[i] = (rem[i - 1] + numbers[i]) % m
    }

    rem.sortBy { it }

    var count = 1

    for (i in 0 until n - 1) {
        if (rem[i] != rem[i + 1]) {
            if (rem[i] == 0) answer += combination(count + 1, 2)
            else answer += combination(count, 2)
            count = 1
        } else {
            count++
        }
    }

    if (count > 1) {
        if (rem.last() == 0) answer += combination(count + 1, 2)
        else answer += combination(count, 2)
    }

    if (count == 1 && rem.last() == 0) answer += combination(count + 1, 2)

    bw.write("$answer\n")
  
    bw.flush()
}

