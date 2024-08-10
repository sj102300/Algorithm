//[골드4] 17404.RGB거리2 https://www.acmicpc.net/problem/17404

import { createRequire } from 'module';
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let data = input.slice(1).map((e) => e.split(' ').map((v) => +v));

function solution(n, data) {

    let answer = Number.MAX_SAFE_INTEGER;

    //여기 반복문은 첫집으로 각각 R,G,B를 칠하는 경우 세가지
    for (let i = 0; i < 3; i++) {

        //무한값으로 dp배열을 초기화
        let dp = Array.from({ length: n }, ()=>new Array(3).fill(987654321));

        //첫번째 집을 r, g, b 컬러로 칠하기. 만약 r로 칠했다면 dp[0][1], dp[0][2]는 Inf 값임. 그래서 dp를 하는도중에 고려하지않게될것.
        dp[0][i] = data[0][i];
        
        //두번째 집부터는 dp로. 
        for (let j = 1; j < n; j++) {
            dp[j][0] = data[j][0] + Math.min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = data[j][1] + Math.min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = data[j][2] + Math.min(dp[j - 1][0], dp[j - 1][1]);
        }

        for(let k = 0; k < 3; k++){
           if(k !== i){     //첫번째 칠한 집과 마지막에 칠한집이 같지않은 경우에만
            answer = Math.min(answer, dp[n-1][k]); //최소비용으로 업데이트
           }
        }
    }

    console.log(answer);

}

solution(n, data);