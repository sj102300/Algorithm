//[골드4] 9663.N-Queen https://www.acmicpc.net/problem/9663

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let N = +fs.readFileSync('dev/stdin', 'utf-8').trim();

let answer = 0;

let v1 = Array.from({ length: N }, () => 0);  //열 체크
let v2 = Array.from({ length: 2 * N - 1 }, () => 0); // i+j 대각선 체크
let v3 = Array.from({ length: 2 * N - 1 }, () => 0); //i-j 대각선 체크

function btrk(m) {

    if (m === N) {
        //종료조건
        answer++;
        return;
    }

    for (let i = 0; i < N; i++) {
        if (v1[i] === 0 && v2[m + i] === 0 && v3[m - i + N - 1] === 0) {
            v1[i] = v2[m + i] = v3[m - i + N - 1] = 1;
            btrk(m + 1);
            v1[i] = v2[m + i] = v3[m - i + N - 1] = 0;
        }
    }

}

btrk(0);

console.log(answer);