fun main() {
    val n = readln().toInt()
    var answer = 0L
    var zero = 1L
    var one = 0L


    if (n > 2) {
        repeat(n - 2) {
            val newZero: Long = zero + one
            val newOne: Long = zero
    
            zero = newZero
            one = newOne
        }
    }
    
    answer = zero + one

    println(answer)
}