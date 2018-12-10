// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://leetcode.com/problems/maximal-rectangle/

/*

Observe that the rectangle with maximum area will be the maximum will have the height as one of the heights given.

The greedy nature of each height h(i) is to find the smaller h(l) and h(r) to the left and right and use it to calculate h(i) * (r - l - 1)

*/

// https://stackoverflow.com/a/35931960/1199846
// http://tech-queries.blogspot.com/2011/03/maximum-area-rectangle-in-histogram.html

var largestRectangleArea = (heights) => {


	let Stack = [] // to find Li and Ri for each i
	let MaxBaseWidth = [] // for each i, store the max base width, calculate area with height later

	for (let i = 0; i < heights.length; i++) {

		while (Stack.length > 0) {
			if (heights[i] <= heights[Stack.slice(-1)[0]]) {
				Stack.pop()
			} else {
				break
			}

		}

		let Li
		if (Stack.length === 0) {
			Li = -1
		} else {
			Li = Stack.pop()
		}

		// For 0, its 0, For 1, its 0 or 1, storing indices!
		MaxBaseWidth[i] = i - Li - 1
		Stack.push(i)
	}

	// Reset for Ri
	Stack.length = 0

	for (let i = heights.length - 1; i >=0; i--) {

		while (Stack.length > 0) {
			if (heights[i] <= heights[Stack.slice(-1)[0]]) {
				Stack.pop()
			} else {
				break
			}

		}

		let Ri
		if (Stack.length === 0) {
			Ri = i
		} else {
			Ri = Stack.pop()
		}

		// For 0, its 0, For 1, its 0 or 1, storing indices!
		MaxBaseWidth[i] += (Ri - i - 1)
		Stack.push(i)
	}

	// console.log(MaxBaseWidth)

	let Areas = MaxBaseWidth.map((i, j) => (i + 1) * heights[j])


	return Math.max(...Areas)
       
}          



console.log(largestRectangleArea([1, 2, 3]))
console.log(largestRectangleArea([2,1,5,6,2,3]))