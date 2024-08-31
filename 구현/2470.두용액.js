//[골드5] 2470.두용액 https://www.acmicpc.net/problem/2470

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let data = input[1].split(' ').map((V) => +V).sort((a, b) => a - b);
// console.log(data);

function solution(n, data) {

    //처음 부터 산성만, 알칼리성만 주어지는 경우 앞에있는거 두개를 합치는게 가장 0에 가까움
    if (data[0] >= 0 && data.at(-1) > 0) {
        return [data[0], data[1]].join(' ');
    }
    else if (data[0] < 0 && data.at(-1) <= 0) {
        return [data.at(-2), data.at(-1)].join(' ');
    }

    let minAbs = Math.abs(data[0] + data.at(-1));
    let answer = [data[0], data.at(-1)];

    let start = 0;
    let end = data.length - 1;

    while (start < end) {
        let tmpAbs = Math.abs(data[start] + data[end]);
        if (tmpAbs < minAbs) {
            minAbs = tmpAbs;
            answer = [data[start], data[end]];
        }

        if (data[start] + data[end] > 0) {
            end--;
        }
        else if (data[start] + data[end] < 0) {
            start++;
        }
        else { //합이 0이되는 순간
            return [data[start], data[end]].join(' ');
        }
    }
    return answer.join(' ');
}

console.log(solution(n, data))
