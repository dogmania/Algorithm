import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val result = ArrayDeque<Int>()
    val answer = mutableListOf<Char>()
    val st = Stack<Int>()
    var curNum = 1

    repeat(n) {
        result.addLast(br.readLine().toInt())
    }

    while(result.isNotEmpty()) {
        while(curNum <= result.first()) {
            st.push(curNum)
            answer.add('+')
            curNum++
        }

        if (st.peek() == result.first()) {
            st.pop()
            result.removeFirst()
            answer.add('-')
        } else {
            answer.add('n')
            break
        }
    }

    if (answer.last() == 'n') bw.write("NO\n")
    else bw.write("${answer.joinToString("\n")}\n")
  
    bw.flush()
}

