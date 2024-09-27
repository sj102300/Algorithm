//[골드5] 23843.콘센트 https://www.acmicpc.net/problem/23843

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input[0].split(' ').map((v) => +v);
let data = input[1].split(' ').map((V) => +V).sort((a, b) => a - b);

function solution(N, M, data) {

    let dataMap = {};
    let dataSet = [...new Set(data)].sort((a, b) => a - b);
    for (let i = 0; i < data.length; i++) {
        if (dataMap[data[i]]) {
            dataMap[data[i]]++;
        }
        else {
            dataMap[data[i]] = 1;
        }
    }

    let answer = 0;

    let flag = 1 //cycle이 안끝났으면 0, 새로운 사이클이면 1
    let leftTime = M;
    while (dataSet.length) {
        let maxTime = dataSet.pop();
        if (flag === 1) {
            answer += maxTime;
            leftTime = M * maxTime;
        }
        // console.log(cur, leftTime, answer, flag);
        if (dataMap[maxTime] * maxTime > leftTime) {
            dataMap[maxTime] -= leftTime / maxTime
            dataSet.push(maxTime);
            flag = 1;
        }
        else if (dataMap[maxTime] * maxTime === leftTime) {
            dataMap[maxTime] = 0;
            flag = 1;
        }
        else {
            flag = 0;
            leftTime -= dataMap[maxTime] * maxTime;
            dataMap[maxTime] = 0;
        }
    }

    return answer;

}

console.log(solution(N, M, data));