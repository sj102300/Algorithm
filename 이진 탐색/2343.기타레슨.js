//[실버1] 2343.기타레슨 https://www.acmicpc.net/problem/2343

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input[0].split(' ').map(Number);
let data = input[1].split(' ').map(Number);

function isValidSize(data, size, m) {
    
    let current =0;
    let need =0;

    for(let i=0;i<data.length;i++){
        if(data[i] > size || need > m)
            return false;
        
        if(current === 0){
            current += data[i];
            need++;
        }
        else{
            if(current + data[i] < size){
                current += data[i];
            }
            else if(current + data[i] === size){
                current = 0;
            }
            else{
                current = data[i];
                need++;
            }
        }
        if(need > m)
            return false;
    }

    return true;
}

function solution(n, m, data) {

    let left = Math.min(...data);
    let right = data.reduce((acc, cur) => acc + cur, 0);
    let size = Math.floor((left + right) / 2);

    let answer = size;

    while (left <= right) {
        size = Math.floor((left + right) / 2)
        // console.log(left, right, answer, size);
        if (isValidSize(data, size, m)) {
            answer = size;
            right = size - 1;
        }
        else {
            left = size + 1;
        }
    }
    return answer;
}

console.log(solution(n, m, data));