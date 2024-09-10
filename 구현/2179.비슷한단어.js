//[골드4] 2179.비슷한단어 https://www.acmicpc.net/problem/2179

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]
let data = input.slice(1);

function solution(n, data) {

    let byfirstLetter = {};
    data.forEach((word) => {
        if (byfirstLetter[word[0]]) {
            byfirstLetter[word[0]].push(word);
        } else {
            byfirstLetter[word[0]] = [word]

        }
    })

    let maxSame = 0;
    let answer = [data[0], data[1]];

    for (let key in byfirstLetter) {
        for (let i = 0; i < byfirstLetter[key].length; i++) {
            let word1 = byfirstLetter[key][i];
            for (let j = i + 1; j < byfirstLetter[key].length; j++) {
                let word2 = byfirstLetter[key][j];
                let tmp = 0
                let len = word1.length > word2.length ? word2.length : word1.length
                for (let k = 0; k < len; k++) {
                    if (word1[k] === word2[k]) {
                        tmp++;
                    }
                    else {
                        break;
                    }
                }
                if(tmp > maxSame){
                    answer = [word1, word2]
                    maxSame = tmp;
                }
            }
        }
    }

    return answer;

}

console.log(solution(n, data).join('\n'));