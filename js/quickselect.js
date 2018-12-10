// http://www.cs.yale.edu/homes/aspnes/pinewiki/QuickSelect.html
// QuickSelect(A, k)
//   let r be chosen uniformly at random in the range 1 to length(A)
//   let pivot = A[r]
//   let A1, A2 be new arrays
//   # split into a pile A1 of small elements and A2 of big elements
//   for i = 1 to n
//     if A[i] < pivot then
//       append A[i] to A1
//     else if A[i] > pivot then
//       append A[i] to A2
//     else
//       # do nothing
//   end for
//   if k <= length(A1):
//     # it's in the pile of small elements
//     return QuickSelect(A1, k)
//   else if k > length(A) - length(A2)
//     # it's in the pile of big elements
//     return QuickSelect(A2, k - (length(A) - length(A2))
//   else
//     # it's equal to the pivot
//     return pivot

const quickSelect = (nums, k, start=0, stop=nums.length - 1) => {
    let pivot = nums[stop]
    let pindex = start
    let i
    for (i = start; i < stop; i++) {
        if (nums[i] < pivot) {
            [nums[i], nums[pindex]] = [nums[pindex], nums[i]]
            pindex++
        }
    }
    [nums[pindex], nums[i]] = [nums[i], nums[pindex]]
    
    console.log(nums, k, start, stop, pindex)
    // stop case
    if (pindex === k) {
        return nums[pindex]
    } else if (k > pindex) {
        return quickSelect(nums, pindex + 1, stop, k)  
    } else {
        return quickSelect(nums, start, pindex - 1, k)
    }
};

console.log(quickSelect([6, 2, 5, 4, 3, 1, 7, 8], 4))