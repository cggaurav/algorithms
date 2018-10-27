// PROBLEM 1: https://leetcode.com/problems/3sum/
// PROBLEM 2: https://leetcode.com/problems/3sum-closest/

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = (nums, target = 0) => {
    
    nums.sort((a, b) => a - b)

    // console.log(nums)

    let solutions = []
    
    for(let i = 0; i < nums.length - 2; i++) {

        if (nums[i] === nums[i-1] && i > 0) {
            continue
        }

        let j = i + 1
        let k = nums.length - 1
        
        while (j < k) {
            // console.log(i, j, k)
            let sum = nums[i] + nums[j] + nums[k]
        
            if (sum > target) {
                k--
                while(nums[k] === nums[k+1] && j < k) {
                    k--
                }

            } else if (sum < target) {

                j++
                while(nums[j] === nums[j-1] && j < k) {
                    j++
                }
                

            } else {
                solutions.push([nums[i], nums[j], nums[k]])
                j++
                k--
                
                while(nums[j] === nums[j-1] && j < k) {
                    j++
                }
                while(nums[k] === nums[k+1] && j < k) {
                    k--
                }
            }
            
        }        

    }
    
    return solutions
    
}

// console.log(threeSum([0,0,0,0]))
// console.log(threeSum([1,-1,-1,0]))
// console.log(threeSum([-1,0,1,2,-1,-4]))
console.log(threeSum([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]))