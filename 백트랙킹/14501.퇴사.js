//[실버3] 14501.퇴사 https://www.acmicpc.net/problem/14501

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input.shift();
input = input.map((v) => v.split(' ').map((e) => +e));

let answer = 0;

function btrk(n, sum) {

    if (n >= N) {
        answer = Math.max(answer, sum);
        return;
    }

    let [t, p] = input[n];
    if (n + t <= N) {  //오늘 상담을 하거나
        btrk(n + t, sum + p);
    }
    btrk(n + 1, sum);   //안하거나

}

btrk(0, 0);

console.log(answer);