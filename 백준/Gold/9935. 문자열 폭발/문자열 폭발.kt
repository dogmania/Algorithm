fun main() {
    val s = readln()
    val boom = readln()
    val boomLen = boom.length
    val answer = StringBuilder()

    for (c in s) {
        answer.append(c)

        if (answer.length >= boomLen && answer.substring(answer.length - boomLen, answer.length) == boom) {
            answer.delete(answer.length - boomLen, answer.length)
        }
    }

    if (answer.isEmpty()) println("FRULA")
    else println(answer.toString())
}