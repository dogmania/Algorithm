fun main() {
    var T = readln().toInt()

    while(T > 0) {
        val w = readln()
        val k = readln().toInt()
        val mp = mutableMapOf<Char, MutableList<Int>>()
        var min = 10001
        var max = -1

        if (k == 1) {
            println("1 1")
            T -= 1
            continue
        }

        for (i in 0 until w.length) {
            mp.getOrPut(w[i]) { mutableListOf() }.add(i)
        }

        for (m in mp) {
            if (m.value.size >= k) {
                for (i in 0 until m.value.size - k + 1) {
                    val length = m.value[i + k - 1] - m.value[i] + 1
                    if (min > length) {
                        min = length
                    }
                    if (max < length) {
                        max = length
                    }
                }
            }
        }

        if (min == 10001) println(-1)
        else println("$min $max")

        T -= 1
    }
}
