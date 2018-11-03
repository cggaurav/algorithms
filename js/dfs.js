// Depth First Traversals:
// (a) Inorder (Left, Root, Right) : 4 2 5 1 3
// (b) Preorder (Root, Left, Right) : 1 2 4 5 3
// (c) Postorder (Left, Right, Root) : 4 5 2 3 1

const matrix =  [[1, 1, 0, 0, 1, 0],
                [1, 0, 1, 0, 1, 0],
                [0, 1, 0, 1, 0, 0],
                [0, 0, 1, 0, 1, 1],
                [1, 1, 0, 1, 0, 0],
                [0, 0, 0, 1, 0, 0]]

// Adjacency matrix ^


function DFS(matrix) {

    const DIRECTIONS = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    const N = matrix.length, M = matrix[0].length
    const visited = matrix.map(row => Array(row.length).fill(false))

    console.log(visited, N, M)

    function dfs(i, j) {

        if (visited[i][j]) 
            return

        visited[i][j] = true

        DIRECTIONS.forEach(direction => {
            const row = i + direction[0], col = j + direction[1]
            // Boundary check.
            if (row < 0 || row >= N || col < 0 || col >= M) {
                return
            }

            // Valid neighbor check.
            if (matrix[row][col] !== 1) {
                return
            }

            dfs(row, col)
        })
    }

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (!visited[i][j]) {
                dfs(i, j)
            }
        }
    }

    return visited
}

console.log(DFS(matrix))

