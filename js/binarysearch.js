let binarySearchQ = (list, search) => {
    let guess,
        min = 0,
        max = list.length - 1	

    while(min <= max){
        guess = Math.floor((min + max) /2)
	if(list[guess] === search)
	    return guess
	else if(list[guess] < search)
	    min = guess + 1
	else
	    max = guess - 1	
    }
	
    return -1
}


console.log(binarySearchQ([1, 2, 3, 4, 5], 1))
console.log(binarySearchQ([1, 2, 3, 4, 5], 4))
console.log(binarySearchQ([1, 2, 3, 4, 5], 0))
console.log(binarySearchQ([1, 2, 3, 4, 5], 6))
