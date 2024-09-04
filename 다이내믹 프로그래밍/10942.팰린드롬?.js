//[골드4] 10942.팰린드롬? https://www.acmicpc.net/problem/10942

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = Number(input.shift());
let array = input.shift().split(' ').map((V) => +V);

let m = Number(input.shift());
let questions = input.map((v) => v.split(' ').map((elem) => +elem - 1));


function solution(n, m, array, questions) {

    let dp = Array.from({ length: n }, () => -1); //홀수개일때의 dp, 기준점은 i
    let dpEven = Array.from({ length: n - 1 }, () => -1); //짝수개일때의 dp, 기준점이 i, i+1

    let answer = [];

    questions.forEach(([S, E]) => {

        //범위가 홀수개
        if ((E - S) % 2 === 0) {
            let targetIdx = (E + S) / 2;

            if (dp[targetIdx] === -1) {
                dp[targetIdx] = 0;
                let start = targetIdx - 1;
                let end = targetIdx + 1;
                while (start >= 0 && end < n && array[start] === array[end]) {
                    dp[targetIdx]++;
                    start--;
                    end++;
                }
            }

            if (E - targetIdx <= dp[targetIdx]) {
                answer.push(1);
            }
            else {
                answer.push(0);
            }

        }
        //범위가 짝수개
        else {
            let evenIdx = Math.floor((E + S) / 2);

            if (dpEven[evenIdx] === -1) {
                dpEven[evenIdx] = 0;
                let evenStart = evenIdx;
                let evenEnd = evenIdx + 1;

                while (evenStart >= 0 && evenEnd < n && array[evenStart] === array[evenEnd]) {
                    dpEven[evenIdx]++;
                    evenStart--;
                    evenEnd++;
                }
            }

            if (evenIdx - S < dpEven[evenIdx]) {
                answer.push(1);
            }
            else {
                answer.push(0);
            }
        }
    })

    return answer.join('\n');
}

console.log(solution(n, m, array, questions))