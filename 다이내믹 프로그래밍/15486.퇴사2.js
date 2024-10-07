//[골드5] 15486.퇴사2 https://www.acmicpc.net/problem/15486

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input.shift()

let data = input.map((v) => v.split(' ').map((e) => +e));

let groupByEndDay = {};
data.forEach(([needed, cost], start) => {
    let endDay = start + needed;
    if (groupByEndDay[endDay]) {
        groupByEndDay[endDay].push([start, cost]);
    }
    else {
        groupByEndDay[endDay] = [[start, cost]];
    }
})

function solution(N, groupByEndDay, data) {

    //dp[i] = i번째날에 퇴사를 했을 때, 벌 수 있는 최대 이익
    let dp = Array.from({ length: N + 1 }, () => 0);

    // for (let i = 1; i <= N; i++) {
    //     let [todayT, todayP] = data[i - 1];
    //     if (i + todayT - 1 <= N) { //유효한 인덱스 내에서
    //         dp[i + todayT - 1] = Math.max(dp[i + todayT - 1], dp[i - 1] + todayP) //오늘 주어진 상담을 시작했을때 dp배열을 갱신
    //     }
    //     dp[i] = Math.max(dp[i], dp[i - 1]);
    // }

    for (let i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        groupByEndDay[i]?.forEach(([start, cost]) => {
            dp[i] = Math.max(dp[start] + cost, dp[i]);
        })
    }

    return dp[N];
}

console.log(solution(N, groupByEndDay, data));