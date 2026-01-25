import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val numbers = br.readLine().split(" ").map { it.toInt() }.toMutableList()
    var answer = 0

    numbers.sortBy { it }
    
    for (i in 0 until n) {
        var left = 0
        var right = n - 1

        while (left < right) {
            if (left == i) {
                left++
                continue
            }

            if (right == i) {
                right--
                continue
            }

            val sum = numbers[left] + numbers[right]

            if (sum == numbers[i]) {
                answer++
                break
            } else if (sum < numbers[i]) left++
            else right--
        }
    }

    bw.write("$answer\n")
  
    bw.flush()
}

