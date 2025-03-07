import java.util.*
import java.io.*
import kotlin.math.max

fun combineCards(cards: PriorityQueue<Int>): Int {
    var result = 0

    while(cards.size >= 2) {
        val card1 = cards.poll()
        val card2 = cards.poll()
        val sum = card1 + card2

        cards.add(sum)
        result += sum
    }

    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val cards = PriorityQueue<Int>()
    var answer = 0

    for (i in 0 until n) {
        val num = br.readLine().toInt()

        cards.add(num)
    }

    if(cards.size > 1) answer = combineCards(cards)

    println(answer)
}