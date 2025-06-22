import java.util.*
import java.io.*
import kotlin.math.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val n = br.readLine().toInt()
    val input = br.readLine()
    val st = Stack<Double>()
    val mp = mutableMapOf<Char, Double>()
    val len = input.length
    
    for (i in 0 until len) {
        when(input[i]) {
            '*' -> {
                val num2 = st.pop()
                val num1 = st.pop()

                st.push(num1 * num2)
            }
            '+' -> {
                val num2 = st.pop()
                val num1 = st.pop()

                st.push(num1 + num2)
            }
            '/' -> {
                val num2 = st.pop()
                val num1 = st.pop()

                st.push(num1 / num2)
            }
            '-' -> {
                val num2 = st.pop()
                val num1 = st.pop()

                st.push(num1 - num2)
            }
            else -> {
                val num = mp.getOrDefault(input[i], -1.0)

                if (num == -1.0) {
                    val newNum = br.readLine().toDouble()

                    mp[input[i]] = newNum

                    st.push(newNum)
                } else {
                    st.push(num)
                }
            }
        }
    }

    bw.write(String.format("%.2f", st.peek()))

    bw.flush()
    bw.close()
    br.close()
}