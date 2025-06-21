import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val tc = br.readLine().toInt()
    val answer = mutableListOf<String>()

    repeat(tc) {
        val input = br.readLine()
        val list = LinkedList<Char>()
        val cursor = list.listIterator()

        for (c in input) {
            when (c) {
                '<' -> if (cursor.hasPrevious()) cursor.previous()
                '>' -> if (cursor.hasNext()) cursor.next()
                '-' -> if (cursor.hasPrevious()) {
                    cursor.previous()
                    cursor.remove()
                }
                else -> cursor.add(c)
            }
        }

        answer.add(list.joinToString(""))
    }

    bw.write("${answer.joinToString("\n")}\n")

    bw.flush()
    bw.close()
    br.close()
}