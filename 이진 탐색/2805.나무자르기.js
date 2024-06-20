//[실버2] 2805.나무자르기 https://www.acmicpc.net/problem/2805

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input[0].split(' ').map(Number);
let data = input[1].split(' ').map(Number);

function isValidHeight(array, m, height){

    let sum =0;
    for(let i=0;i<array.length;i++){
        sum += array[i] - height > 0 ? array[i] - height : 0;
        if(sum >= m)
            return true;
    }
    if(sum >= m){
        return true;
    }
    return false;
}

function solution(n, m, data){
    
    let left = 0;
    let right = Math.max(...data);
    
    let height;

    let answer= left;

    while(left<=right){
        height= Math.floor((left+right)/2);
        if(isValidHeight(data, m, height)){
            answer = height;
            left = height + 1;
        }
        else{
            right = height - 1;
        }
    }
    return answer;
}

console.log(solution(n, m, data));