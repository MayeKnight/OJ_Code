import java.util.*
import kotlin.math.max

fun main() {
    val scan = Scanner(System.`in`)
    val n = scan.nextInt()

    for (i in 1..n) {
        val k = scan.nextInt()
        var m = scan.nextInt()

        m %= 3 * k
        println(max(2 * k - m, 0))
    }
}
