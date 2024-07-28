//[골드2] 2695.공 https://www.acmicpc.net/problem/2695

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let p = +input[0]
let info = input.slice(1).map((v) => v.split(' ').map((v) => +v));

function calc(dp, b, floor) {
    if (dp[b][floor] >= 0) return dp[b][floor];  //이미 계산된거면 그대로 return

    let result = dp[1][floor];  //최대 층높이수만큼은 계산해봐야함.
    for (let now = 2; now <= floor; now++) {  //밑에서부터 위로 올라가면서 
        //calc(dp, b-1, now-1) => 공이 깨진 경우 (시도횟수 줄이고, 밑으로내려가기)
        //calc(dp, b, floor-now) => 공이 안깨진 경우(시도횟수는 그대로, 남은층(총 층 - 현재 시도한 층)을 모두 확인해야함)
        result = Math.min(result, 1 + Math.max(calc(dp, b - 1, now - 1), calc(dp, b, floor - now)));
    }
    dp[b][floor] = result;
    return result;
}

function solution(p, info) {

    //dp[b][floor] = b개의 공으로 floor층을 탐색하는 경우
    let dp = Array.from({ length: 51 }, () => Array(1001).fill(-1));
    for (let i = 1; i < 1001; i++) {
        dp[1][i] = i;  //공이 1개밖에 없으면 모든 층에서 처음부터 끝까지 떨어뜨려보아야함. 
    }
    for (let i = 2; i < 51; i++) {
        dp[i][1] = 1;  //확인할 층이 1개만 있으면 1번만 확인 하면됨.
    }

    info.forEach(([b, floor]) => {
        console.log(calc(dp, b, floor));
    })
}

solution(p, info);