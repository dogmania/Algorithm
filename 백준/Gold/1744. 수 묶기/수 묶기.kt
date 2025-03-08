import java.util.*
import java.io.*
import kotlin.math.max

fun calculateMax(nums: PriorityQueue<Int>): Int {
    var result = 0

    while(nums.size > 1) {
        val num1 = nums.poll()
        val num2 = nums.poll()
        
        if (num1 == 1 || num2 == 1) {
            result += num1 + num2
        } else {
            result += num1 * num2
        }
    }

    if (nums.size == 1) {
        result += nums.poll()
    }

    return result
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val negative = PriorityQueue<Int>()
    val positive = PriorityQueue<Int>(compareByDescending { it })
    var answer = 0
    
    repeat(n) {
        val num = br.readLine().toInt()

        if (num > 0) positive.add(num)
        else if (num <= 0) negative.add(num)
    }

    answer += calculateMax(negative) + calculateMax(positive)

    println(answer)
}