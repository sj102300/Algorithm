//[골드3] 2109.순회강연 https://www.acmicpc.net/problem/2109

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
input = input.map((v) => v.split(' ').map((e) => +e));  //p d

function solution(n, data) {

    //p 내림차순 정렬, d 내림차순 정렬
    data = data.sort((a, b) => b[0] - a[0] === 0 ? b[1] - a[1] : b[0] - a[0]);

    let maxD = -1;
    for (let i = 0; i < n; i++) {
        maxD = Math.max(maxD, data[i][1]);
    }

    let dp = Array.from({ length: maxD + 1 }, () => 0);


    for (let i = 0; i < n; i++) {
        let [p, d] = data[i];

        if (dp[d] === 0)
            dp[d] = p;
        else {
            for(let prevD = d-1; prevD > 0; prevD--){
                if(dp[prevD] === 0){
                    dp[prevD] = p;
                    break;
                }
            }
        }
    }

    return dp.reduce((acc, cur) => acc + cur, 0);

}

console.log(solution(n, input));