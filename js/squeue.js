// A special queue that has a limited size N but acts as a queue to do all operations in O(1)

class SpecialQueue {
    
    constructor (N) {
        this.list = []
        this.N = N
        
        // CIRCULAR APPROACH
        this.head = -1
        this.tail = -1
        this.size = 0
    }
    
    push(value) {
        // Tail is alwasy the index you can push to
        if(this.size < this.N) {

            if (this.size === 0) {
                this.head = 0
                this.tail = 0
            }
            
            this.list[this.tail] = value

            this.tail++
            this.tail = this.tail % this.N

            this.size++

            return this.list
            
        } else {
            console.error("CANNOT ADD")
            return this.list
        }
        
    }
    
    pop() {
        
        console.log('POP')
        if (this.size === 0) {
            return null
        } else {
            this.size--
            let currHead = this.head
            let currValue = this.list[currHead]
            this.list[currHead] = null
            this.head ++
            this.head = this.head % this.N
            return currValue
        }
        
    }
    
    peek(index) {
        console.log(`PEEK at INDEX: ${index}: `)
        
        return this.list[index - 1]
        
    }
    
}


let sq = new SpecialQueue(5)

console.log(sq.push(1))
console.log(sq.push(2))
console.log(sq.push(3))

console.log(sq.peek(1))
console.log(sq.peek(2))
console.log(sq.peek(3))

console.log(sq.push(4))

console.log(sq.pop())
console.log(sq.pop())
console.log(sq.push(5))
console.log(sq.push(6))
console.log(sq.push(7))
console.log(sq.pop())
console.log(sq.pop())

console.log(sq.pop())

console.log(sq.peek(1))
console.log(sq.push(8))
