// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// This is modelled as an Adjacency list where you know the neightbors of each node V as V.left, V.right or V.neightbors
// OR

const graph = 	[[1, 1, 0, 0, 1, 0],
				[1, 0, 1, 0, 1, 0],
				[0, 1, 0, 1, 0, 0],
				[0, 0, 1, 0, 1, 1],
				[1, 1, 0, 1, 0, 0],
				[0, 0, 0, 1, 0, 0]]

// Adjacency matrix ^


const bfs = (graph, startNode = 0, targetNode = 5) => {

	let Q = []
	let Parents = {}
	let Visited = {}
	let Levels = {}
	
	// ROOT or NODE 0
	Q.push(startNode)

	Parents[startNode] = null
	Visited[startNode] = true
	Levels[startNode] = 0

	while(Q.length > 0) {

		let current = Q.shift()	

		if (current === targetNode) {
			// We are done here.
		}

		// for all neightbors, this could be a ADJACENCY (MATRIX or LIST)
		for (let i = 0; i < graph[current].length; i++) {
			if (graph[current][i] === 1 && !Visited[i]) {
				console.log()
				
				Parents[i] = current
				Levels[i] = Levels[current] + 1
				Visited[i] = true

				Q.push(i)
			}
		}

	}

	return [Visited, Parents, Levels]
    
}

console.log(bfs(graph))

