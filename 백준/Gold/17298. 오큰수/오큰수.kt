import java.io.*
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = br.readLine().toInt()
    val nums = IntArray(n)
    val answer = IntArray(n)
    val input = StringTokenizer(br.readLine())
    val st = Stack<Int>()

    repeat(n) { i ->
        nums[i] = input.nextToken().toInt()
    }

    for (i in 0 until n) {
        if (st.isEmpty()) st.push(i)
        else {
            while(st.isNotEmpty() && nums[st.peek()] < nums[i]) {
                answer[st.pop()] = nums[i]
            }

            st.push(i)
        }
    }

    while(st.isNotEmpty()) {
        answer[st.pop()] = -1
    }

    bw.write("${answer.joinToString(" ")}\n")
  
    bw.flush()
}

