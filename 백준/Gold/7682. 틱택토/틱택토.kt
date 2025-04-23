import java.util.*
import java.io.*
import kotlin.math.max

enum class GameResult {
    X, O, DRAW, INVALID
}

fun countUnit(str: String): Pair<Int, Int> {
    var count1 = 0
    var count2 = 0

    for (s in str) {
        if (s == 'X') count1++
        else if (s == 'O') count2++
    }

    return Pair(count1, count2)
}

fun calculateWinner(str: String): GameResult {
    var winner = GameResult.DRAW

    for (i in listOf(0, 3, 6)) {
        if (str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {
            if (str[i] == 'X') {
                if (winner != GameResult.O) winner = GameResult.X
                else return GameResult.INVALID
            }
            else if (str[i] == 'O') {
                if (winner != GameResult.X) winner = GameResult.O
                else return GameResult.INVALID
            }
        }
    }

    for (i in listOf(0, 1, 2)) {
        if (str[i] == str[i + 3] && str[i + 3] == str[i + 6]) {
            if (str[i] == 'X') {
                if (winner != GameResult.O) winner = GameResult.X
                else return GameResult.INVALID
            }
            else if (str[i] == 'O') {
                if (winner != GameResult.X) winner = GameResult.O
                else return GameResult.INVALID
            }
        }
    }

    if (str[0] == str[4] && str[4] == str[8]) {
        if (str[0] == 'X') {
            if (winner != GameResult.O) winner = GameResult.X
            else return GameResult.INVALID
        }
        else if (str[0] == 'O') {
            if (winner != GameResult.X) winner = GameResult.O
            else return GameResult.INVALID
        }
    }

    if (str[2] == str[4] && str[4] == str[6]) {
        if (str[2] == 'X') {
            if (winner != GameResult.O) winner = GameResult.X
            else return GameResult.INVALID
        }
        else if(str[2] == 'O') {
            if (winner != GameResult.X) winner = GameResult.O
            else return GameResult.INVALID
        }
    }

    return winner
}

fun isValidGame(str: String, countX: Int, countO: Int): Boolean {

    when(calculateWinner(str)) {
        GameResult.X -> {
            if (countX == countO) return false
        }
        GameResult.O -> {
            if (countX > countO) return false
        }
        GameResult.DRAW -> {
            if (countX + countO < 9) return false
        }
        else -> return false
    }

    return true
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    
    while(true) {
        val input = br.readLine()

        if (input == "end") break

        val (countX, countO) = countUnit(input)
        val dis = countX - countO

        if (dis >= 2 || dis < 0) {
            bw.write("invalid\n")
            continue
        }

        if (isValidGame(input, countX, countO)) {
            bw.write("valid\n")
        } else {
            bw.write("invalid\n")
        }
    }

    bw.flush()
    bw.close()
    br.close()
}