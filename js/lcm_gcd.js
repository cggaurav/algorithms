function lcm_two_numbers(x, y) {
    return Math.abs((x * y) / gcd_two_numbers(x, y))
}

function gcd_two_numbers(x, y) {
    x = Math.abs(x)
    y = Math.abs(y)

    // Euclidean algorithm, use modulo!
    if (y === 0) 
        return x

    return gcd_two_numbers(y, x % y)
}


console.log(gcd_two_numbers(3,15))
console.log(gcd_two_numbers(10,15))

console.log(lcm_two_numbers(3,15))
console.log(lcm_two_numbers(10,15))