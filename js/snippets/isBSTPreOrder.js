
function isBSTR (tree) {

    let N = tree.length

    // EDGE CASES
    if ( N === 0) {
        return true
    }

    if ( N === 1) {
        return true
    }

    if ( N === 2 ) {
        return true
    }

    let stack = []
    let ROOT = tree[0]
    // console.log("BEFORE", tree)

    let RIGHT = null
    let valid = true

    for (let i = 1; i < N; i ++) {
        if (!RIGHT && tree[i] > ROOT) {
            RIGHT = i
        }

        if (RIGHT && tree[i] < ROOT) {
            valid = false
        }
    }

    if (!RIGHT) {
        return true
    }
    return (valid && isBSTR(tree.slice(1, RIGHT)) && isBSTR(tree.slice(RIGHT)))    

    
}


// TODO, take care of equality cases
// console.log(isBSTR([1, 3, 2]))
// console.log(isBSTR([2, 1, 3]))
// console.log(isBSTR([3,2,1,5,4,6]))
// console.log(isBSTR([1,3,4,2]))
// console.log(isBSTR([3,4,5,1,2]))
console.log(isBSTR([3, 2, 1]))



