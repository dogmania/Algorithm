fun main() {
    val n = readln().toInt()
    val m = readln().toInt()
    var arr = readln().split(" ").map{ it.toInt() }.toMutableList()
    var first = 0
    var last = arr.size - 1
    var answer = 0

    arr = arr.sorted().toMutableList()

    while(first < last) {
        val sum = arr[first] + arr[last]

        when {
            sum < m -> {
                first += 1
            }

            sum == m -> {
                answer += 1
                arr.removeAt(first)
                arr.removeAt(last - 1)
                first = 0
                last = arr.size - 1
            }

            else -> {
                last -= 1
            }
        }
    }

    println(answer)
}