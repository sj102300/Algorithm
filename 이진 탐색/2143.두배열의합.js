//[골드3] 2143.두배열의합 https://www.acmicpc.net/problem/2143

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let T = +input[0];
let n = +input[1];
let a = input[2].split(' ').map((v) => +v);
let m = +input[3];
let b = input[4].split(' ').map((v) => +v);

//부배열의 합이 되는 모든 경우의 수를 담은 배열 만들기 -> Asub, Bsub
//A,B모두 정렬
//Asub의 각 원소에서 더해서 T가 될수있는 값은 단 하나. 그게 Bsub에 몇개있는지 이분탐색으로 찾기

function binarySearch(array, target) {

    let left = 0;
    let right = array.length - 1;
    let mid;

    while (left < right) {
        mid = Math.floor((left + right) / 2);
        if (array[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    let num = 0
    while (left < array.length) {
        if (array[left] === target) {
            left++;
            num++;
        }
        else {
            break;
        }
    }
    return num;

}

function solution(T, n, A, m, B) {

    let answer = 0;

    let Asub = {};
    for (let i = 0; i < n; i++) {
        let tmp = 0;
        for (let j = i; j < n; j++) {
            tmp += A[j];
            if(Asub[tmp]){
                Asub[tmp]++;
            }
            else{
                Asub[tmp] = 1;
            }
        }
    }

    let Bsub = [];
    for (let i = 0; i < m; i++) {
        let tmp = 0;
        for (let j = i; j < m; j++) {
            tmp += B[j];
            Bsub.push(tmp);
        }
    }

    Bsub.sort((a, b) => a - b);

    for(let key in Asub){
        let target = T - +key;
        let result = binarySearch(Bsub, target);
        answer += Asub[key] * result;
    }

    return answer;

}

console.log(solution(T, n, a, m, b));