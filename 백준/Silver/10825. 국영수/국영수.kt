import java.util.*

data class Student(
    val name: String,
    val kor: Int,
    val eng: Int,
    val math: Int
)

fun main() {
    val n = readln().toInt()
    val student = mutableListOf<Student>()

    repeat(n) {
        val input = readln().split(" ")
        student.add(Student(input[0], input[1].toInt(), input[2].toInt(), input[3].toInt()))
    }

    student.sortWith(compareByDescending<Student> { it.kor }
        .thenBy { it.eng }
        .thenByDescending { it.math }
        .thenBy { it.name })

    for (stu in student) {
        println(stu.name)
    }
}