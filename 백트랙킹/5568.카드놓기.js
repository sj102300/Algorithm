//[실버4] 5568.카드놓기 https://www.acmicpc.net/problem/5568

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let data = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +data.shift();
let K = +data.shift();

let visited = Array(N).fill(0);
let answer = new Set();

function btrk(n, selectedStr) {
    //[1] 종료조건(기저조건) : n에 관련된것.
    if (n == K) {
        //정답처리 관련 => 여기서!!
        answer.add(selectedStr);
        return;
    }

    for (let j = 0; j < N; j++) {
        //이미 사용한 숫자라면 안됨
        if (visited[j] === 0) {
            visited[j] = 1;
            btrk(n + 1, selectedStr + data[j]);
            visited[j] = 0; //반드시 원상복구
        }
    }
}

btrk(0, '');

console.log(answer.size);