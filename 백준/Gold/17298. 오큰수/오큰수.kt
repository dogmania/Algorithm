import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val num = readLine()!!.split(" ").map{ it.toInt() }
    val answer = MutableList(n) { -1 }
    val stack = Stack<Int>()

    for (i in 0 until n) {
        while(stack.isNotEmpty() && num[stack.peek()] < num[i]) {
            val index = stack.pop()
            answer[index] = num[i]
        }

        stack.push(i)
    }

    println(answer.joinToString(" "))
}