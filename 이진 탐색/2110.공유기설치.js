//[골드4] 2110.공유기설치 https://www.acmicpc.net/problem/2110

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, c] = input[0].split(' ').map((v) => +v);

//오름차순 정렬됨
let data = input.slice(1).map((v) => +v).sort((a, b) => a - b);

function solution(n, c, data) {

    let s = 1; //최소간격
    let e = data.at(-1) - data[0]; //최대간격

    while (s <= e) {
        let distance = Math.floor((s + e) / 2);

        let cnt = 1;
        let prev = data[0];
        for (let cur of data) {
            if (cur - prev < distance)
                continue;
            prev = cur;
            cnt++;
        }
        if (cnt >= c) {
            s = distance + 1;
        }
        else {
            e = distance - 1;
        }
    }

    console.log(e);

}

solution(n, c, data);