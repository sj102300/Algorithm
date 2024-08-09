//[골드5] 11000.강의실배정 https://www.acmicpc.net/problem/11000

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]

let data = input.slice(1).map((e) => e.split(' ').map((v) => +v));

function solution(n, data) {

    let meets = [];
    data.forEach((e, i) => {
        meets.push({
            time: e[0], isStart: 1
        });
        meets.push({
            time: e[1], isStart: -1
        })
    })

    meets = meets.sort((a,b)=> a.time === b.time ? a.isStart - b.isStart : a.time - b.time);

    let answer = 0;
    let cnt = 0;

    meets.forEach((e,i)=>{
        if(e.isStart === 1){
            cnt++;
        }
        else if (e.isStart === -1){
            cnt--;
        }

        answer = Math.max(answer, cnt);
    })

    console.log(answer);

}

solution(n, data);