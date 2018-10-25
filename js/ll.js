class Node {
    constructor(value) {
        this.value = value
        this.next = null
    }
}

class LinkedList {
    constructor() {
        this.head   = null
        this.length = 0
    }
  
    add(value) {
        const nodeToAdd = new Node(value)
        if(!this.head) {
            this.head = nodeToAdd
            this.length++
            return this.head
        } else {
            let curr = this.head
            while(curr.next) {
                curr = curr.next
            }
            curr.next = nodeToAdd;
            this.length++;
            return curr
        }
    }

    get(index) {
        let curr = this.head
        let i = 0
        
        if(index > this.length) return "Doesn't Exist!"
        
        while(i < index) {
            curr = curr.next
            i++
        }
        
        return curr
    }
    
    remove(index) {
        let curr = this.head,
            count       = 0,
            prev    = null
        
        if (index > length) return "Doesn't Exist!"
        
        if(index === 0) {
            this.head = curr.next
            this.length--
          
            return this.head
        }
        
        while(count < index) {
            prev = curr
            curr = curr.next
            count++
        }
        
        prev.next = curr.next
        curr = null
        this.length--
        
        return this.head
    }  
}