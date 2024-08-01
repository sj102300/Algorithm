//[실버1] 1946.신입사원 https://www.acmicpc.net/problem/1946

import { createRequire } from "module";
const require = createRequire(import.meta.url);

// data = [
//     { n: 5, ranking: [[Array], [Array], [Array], [Array], [Array]] },
//     {
//         n: 7,
//         ranking: [
//             [Array], [Array],
//             [Array], [Array],
//             [Array], [Array],
//             [Array]
//         ]
//     }
// ]

const fs = require("fs")
let input = fs.readFileSync('input.txt', 'utf-8').trim().split("\n");
// let input = fs.readFileSync('/dev/stdin', 'utf-8').trim().split('\n');

const T = +input[0];

let data = []
let idx = 1;
while (true) {
    let n = +input[idx];
    let ranking = input.slice(idx + 1, idx + 1 + n).map((elem) => elem.split(' ').map((value) => +value));
    data.push({
        n: n,
        ranking: ranking
    })
    idx = idx + n + 1;
    if (idx >= input.length) break;
}


function solution(T, data) {

    data.map((element) => {
        let ranking = element.ranking.sort((a, b) => a[0] - b[0]);
        let cnt = 1;
        let minSecond = ranking[0][1];
        
        for (let i = 1; i< element.n; i++){
            if (ranking[i][1] < minSecond) {
                cnt++;
                minSecond = ranking[i][1];
            }
        }
        console.log(cnt);
    })
}

solution(T, data);