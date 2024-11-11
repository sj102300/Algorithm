//[골드1] 1799.비숍 https://www.acmicpc.net/problem/1799

import { createRequire } from "module";
const require = createRequire(import.meta.url);

let fs = require('fs');
let map = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let n = map.shift()[0];
let answer = 0;

let v2 = Array(2 * n - 1).fill(0);  //a-b+n-1

let possiblePosition = Array.from({ length: 2 * n - 1 }, () => []);

for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        if (map[i][j] === 1) {
            possiblePosition[i + j].push([i, j]);
        }
    }
}

function btrk(m, bishopNum) {

    if (answer >= bishopNum + 2 * n - 1 - m)  //남은자리에 다 놓아도 정답 갱신 불가(이미 최댓값이 설정이 됨)
        return;

    if (m === 2 * n - 1) {
        //종료조건
        answer = Math.max(answer, bishopNum);
        return;
    }

    let flag = 0;

    possiblePosition[m].forEach(([x, y]) => {
        if (v2[x - y + n - 1] === 0) {
            flag = 1;
            v2[x - y + n - 1] = 1;
            btrk(m + 1, bishopNum + 1);
            v2[x - y + n - 1] = 0;
        }
    })

    if (flag === 0)
        btrk(m + 1, bishopNum);

}

btrk(0, 0)


console.log(answer);