// Test kth bit is set: num & (1 << k) != 0.
// Set kth bit: num |= (1 << k).
// Turn off kth bit: num &= ~(1 << k).
// Toggle the kth bit: num ^= (1 << k).
// To check if a number is a power of 2, num & num - 1 == 0
// To check if odd, num & 1
// Multiplication by 2. x <<= 1

const isPower2 = (num) => {
	return !(num & (num - 1))
}

const setBit = (num, position) => {
	let mask = 1 << position
	return num | mask
}

const clearBit = (num, position) => {
	// We use the ~/NOT operator after placing the bit
	// We want 1s everywhere and 0 only where we want to modify
	let mask = ~(1 << position)
  
  	// We use AND which will modify only the bits compared to 0
  	return num & mask
}

const flipBit = (num, position) => {
	let mask = 1 << position
  	// If the current state of the bit is 0, XOR will return 1
  	// If the bit is 1, XOR will set it to 0
  	return num ^ mask
}

const getBit = (num, position) => {
	let mask = 1 << position
    return (((num & mask) >> position) === 0) ? 0 : 1
}

// console.log(getBit(5, 0))
// console.log(getBit(5, 1))
// console.log(getBit(5, 2))
// console.log(getBit(5, 3))
// console.log(getBit(5, 4))
// console.log(getBit(5, 6))
// console.log(flipBit(6, 2))

// console.log(isPower2(2))
// console.log(isPower2(128))
// console.log(isPower2(127))