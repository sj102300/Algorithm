//[골드4] 1744.수묶기 https://acmicpc.net/problem/1744

import { createRequire } from "module";
const require = createRequire(import.meta.url)

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => +v);

let n = input.shift();


function solution(n, input) {

    let answer = 0;

    let plus = [];
    let minus = [];
    let one = [];
    input.forEach((v) => {
        if(v > 1)
            plus.push(v);
        else if(v<=0)
            minus.push(v);
        else if(v===1)
            one.push(v);
    });
    plus.sort((a, b) => a - b);
    minus.sort((a, b) => b - a);

    while (plus.length >= 2) {
        let [a, b] = [plus.pop(), plus.pop()];
        answer += a*b;
    }

    if(plus.length !== 0){
        answer+=plus.pop();
    }

    answer+=one.length;

    while(minus.length >= 2){
        let [a,b] = [minus.pop(), minus.pop()];
        answer += a*b;
    }

    if(minus.length !== 0){
        answer += minus.pop();
    }

    return answer;

}

console.log(solution(n, input));