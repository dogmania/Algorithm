import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val boundary = if (n % 2 == 0) n / 2 else n / 2 + 1
    var left = 1
    var right = 1
    var answer = 1
    var sum = 1

    while (right < n) {
        if (sum < n) {
            right++
            sum += right
        } else if (sum == n) {
            answer++
            sum -= left
            left++
        } else {
            sum -= left
            left++
        }
    }

    bw.write("$answer\n")
  
    bw.flush()
}

