const val MIN_X = 65
const val MAX_X = 72
const val MIN_Y = 1
const val MAX_Y = 8

fun main() {
    val input = readln()
    val (k, s, N) = input.split(" ")
    val n = N.toInt()
    var king = Pair(k[0].code, k[1].digitToInt())
    var stone = Pair(s[0].code, s[1].digitToInt())
    val mp = mapOf(
        "R" to Pair(1, 0),
        "L" to Pair(-1, 0),
        "B" to Pair(0, -1),
        "T" to Pair(0, 1),
        "RT" to Pair(1, 1),
        "LT" to Pair(-1, 1),
        "RB" to Pair(1, -1),
        "LB" to Pair(-1, -1)
    )

    repeat(n) {
        val move = readln()
        val dx = mp[move]!!.first
        val dy = mp[move]!!.second
        val nx = king.first + dx
        val ny = king.second + dy

        if (nx in MIN_X..MAX_X && ny in MIN_Y..MAX_Y) {
            if (Pair(nx, ny) == stone) {
                val sx = stone.first + dx
                val sy = stone.second + dy

                if (sx in MIN_X..MAX_X && sy in MIN_Y..MAX_Y) {
                    king = Pair(nx, ny)
                    stone = Pair(sx, sy)
                }
            } else {
                king = Pair(nx, ny)
            }
        }
    }

    println(king.first.toChar().toString() + king.second.digitToChar())
    println(stone.first.toChar().toString() + stone.second.digitToChar())
}