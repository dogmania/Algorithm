import java.io.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val materials = br.readLine().split(" ").map { it.toInt() }.toMutableList()
    var right = n - 1
    var left = 0
    var sum = 0
    var answer = 0

    materials.sortBy { it }

    while (left < right) {
        sum = materials[left] + materials[right]

        if (sum > m) right--
        else if (sum < m) left++
        else {
            answer++
            left++
        }
    }

    bw.write("$answer\n")
  
    bw.flush()
}

