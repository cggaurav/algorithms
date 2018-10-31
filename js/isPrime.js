function isPrime(number) {
    let start = 2
    const limit = Math.sqrt(number)
    while (start <= limit) {
        if (number % start++ < 1) return false
    }
    return number > 1
}

console.log(isPrime(1))
console.log(isPrime(2))
console.log(isPrime(5))
console.log(isPrime(100))