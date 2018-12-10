function romanizer(numbers) {
    
    let results = []
    const map = [
      ['', 'I', "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
      ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC'],
      ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM'],
      ['', 'M', 'MM', 'MMM']
    ];

    numbers.forEach((num) => {
        

        let n = num.toString().split('');
        let word = '';
      
        for(let i = 0; i < n.length; i++) {
            word += map[n.length - i - 1][parseInt(n[i])];
        }
      
        results.push(word)
    })

    return results
}

console.log(romanizer([1,2,3,4,5]))