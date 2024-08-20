//[골드4] 1339.단어수학 https://www.acmicpc.net/problem/1339

import {createRequire } from 'module';
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let data = input.slice(1);
function solution(n, data){

    let letterNumberMap = new Map();
    
    for(let i = 0 ;i <data.length; i++){
        for(let j = 0 ; j <data[i].length; j++){
            let cur = 0;
            if(letterNumberMap.has(data[i][j])){
                cur = letterNumberMap.get(data[i][j]);
            }
            cur += Math.pow(10, (data[i].length - j - 1))
            letterNumberMap.set(data[i][j], cur);
        }
    }

    let letterNumberArray = [...letterNumberMap];
    letterNumberArray.sort((a, b)=> b[1] - a[1]);
    let sum =0;
    for(let i=0;i<letterNumberArray.length; i++){
        sum += (9-i) * letterNumberArray[i][1];
    }
    return sum;
}

console.log(solution(n, data));