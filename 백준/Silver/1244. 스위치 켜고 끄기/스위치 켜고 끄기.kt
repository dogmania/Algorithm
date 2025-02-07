import java.util.*

fun main() {
    val n = readln().toInt()
    val switch = readln().split(" ").map{ it.toInt() }.toMutableList()
    val m = readln().toInt()

    repeat(m) {
        val input = readln().split(" ").map{ it.toInt() }

        when (input[0]) {
            1 -> {
                var curValue = input[1]

                while (curValue <= n) {
                    switch[curValue - 1] = if (switch[curValue - 1] == 0) 1 else 0
                    curValue += input[1]
                }
            }
            2 -> {
                var start = input[1]
                var end = input[1]

                while (start in 1..n && end in 1..n) {
                    if (start == end) {
                        switch[start - 1] = if (switch[start - 1] == 0) 1 else 0
                        start -= 1
                        end += 1
                    } else {
                        if (switch[start - 1] == switch[end - 1]) {
                            switch[start - 1] = if (switch[start - 1] == 0) 1 else 0
                            switch[end - 1] = if (switch[end - 1] == 0) 1 else 0
                            start -= 1
                            end += 1
                        } else break
                    }
                }
            }
            else -> {}
        }
    }

    var count = 0
    for (s in switch) {
        print("$s ")
        count += 1

        if (count % 20 == 0) println()
    }
}