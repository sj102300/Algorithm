//[골드3] 23900.알고리즘수업-선택정렬6 https://www.acmicpc.net/problem/23900

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let A = input[1].split(' ').map((v) => +v);
let B = input[2].split(' ').map((v) => +v);

function solution(n, A, B) {

    let pressedA = [...A].sort((a, b) => a - b);

    let AMap = new Map();

    A.forEach((v, i) => {
        AMap.set(v, i);
    })

    let history = [];

    for (let i = n - 1; i >= 0; i--) {
        let tmp = AMap.get(pressedA[i]);  //tmp -> 정렬되기 전에 있던자리, i -> 정렬되고 나서 있어야할 자리
        [A[tmp], A[i]] = [A[i], A[tmp]];
        AMap.set(A[tmp], tmp);
        AMap.set(A[i], i);
        history.push([i, tmp]);
    }

    let sortedIdx = 0;
    for(let i=n-1;i>=0;i--){
        if(pressedA[i] !== B[i]){
            sortedIdx = i;
            break;
        }
    }

    for(let i=sortedIdx; i>=0;i--){
        let [a,b] = history.at(-i-1);
       [ B[a], B[b]] = [B[b], B[a]];
    }

    for(let i=0;i<n;i++){
        if(pressedA[i] !== B[i])
            return 0;
    }

    return 1;
}

console.log(solution(n, A, B));