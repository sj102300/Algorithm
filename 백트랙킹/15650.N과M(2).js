//[실버3] 15650.N과M(2) https://www.acmicpc.net/problem/15650

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [N, M] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

let answer = [];

function btrk(n, selected) {

    if (n === M) {
        answer.push(selected.join(' '));
        return;
    }

    for (let i = selected.at(-1) + 1; i <= N; i++) {
        btrk(n+1, [...selected, i]);
    }

}

for (let i = 1; i <= N; i++) {
    btrk(1, [i]);
}

console.log(answer.join('\n'));