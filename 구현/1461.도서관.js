//[골드4] 1461.도서관 https://www.acmicpc.net/problem/1461

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input[0].split(' ').map((v) => +v);
let data = input[1].split(' ').map((v) => +v);

function solution(n, m, data) {

    let plus = data.filter((v) => v > 0).sort((a, b) => a - b);
    let minus = data.filter((v) => v < 0).map((v) => -v).sort((a, b) => a - b);

    let answer = 0;

    let lastPlus = plus.at(-1);
    let lastMinus = minus.at(-1);

    while (plus.length > 0) {
        answer += plus.pop() * 2;
        for (let i = 0; i < m - 1; i++) {
            plus.pop();
        }
    }

    while (minus.length > 0) {
        answer += minus.pop() * 2;
        for (let i = 0; i < m - 1; i++) {
            minus.pop();
        }
    }

    if(!lastPlus){
        answer -= lastMinus;
    }
    else if(!lastMinus){
        answer -= lastPlus;
    }
    else{
        if(lastPlus > lastMinus){
            answer -= lastPlus;
        }
        else{
            answer -= lastMinus
        }
    }

    return answer;
}

console.log(solution(n, m, data));


//가장 거리가 먼거 m개는 제외 (한번만 더하면됨)