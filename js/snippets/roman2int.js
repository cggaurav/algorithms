var romanToInt = function(s) {
    const VALUES = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };
    let num = 0;
    
    for (let i = 0; i < s.length; i++) {
        const curValue = VALUES[s[i]],
              nextValue = VALUES[s[i + 1]];
        if (curValue < nextValue) {
            num += nextValue - curValue;
            i++;
        } else {
            num += curValue;
        }
    }
    
    return num;
};

console.log(romanToInt('VI'))