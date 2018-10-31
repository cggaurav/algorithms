// https://web.stanford.edu/class/cs124/lec/med.pdf, also Levenstien
const minDistance = function (s, t) {

    let word1 = s.split('')
    let word2= t.split('')

    let m = s.length, n = t.length

    // dp[i][j] is the min edit distance for s[0..i], t[0...j]
    let dp = []

    for (let i = 0; i <= m; i++) {
        dp[i] = new Array(n)
    }

    for (let i = 0; i <= m; i++) {
        dp[i][0] = i
    }

    for (let j = 0; j <= n; j++) {
        dp[0][j] = j
    }

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            // SAME
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]
            }
            else {
                dp[i][j] = Math.min(
                    dp[i - 1][j - 1] + 1,  // REPLACE
                    dp[i - 1][j] + 1, // DELETION/INSERTION
                    dp[i][j - 1] + 1 // REPLACE
                )
            }
        }
    }
   
    return dp[m][n]
}

console.log(minDistance("intention", "execution"))