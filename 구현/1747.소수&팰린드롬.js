//[실버1] 1747.소수&팰린드롬 https://www.acmicpc.net/problem/1747

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let n = +(fs.readFileSync('dev/stdin', 'utf-8').trim());

function isPalin(k) {
    let str = '' + k;
    if (str.length % 2 === 0) {
        let start = str.length / 2;
        let end = start - 1;
        while (start >= 0 && end <= str.length - 1) {
            if (str[start] !== str[end])
                return false;
            start--;
            end++;
        }
    }
    else {
        let start = Math.floor(str.length / 2) - 1
        let end = start + 2;
        while (start >= 0 && end <= str.length - 1) {
            if (str[start] !== str[end])
                return false;
            start--;
            end++;
        }
    }
    return true;
}

function isPrime(k) {
    if(k==1)
        return false;
    for (let i = 2; i <= Math.floor(Math.sqrt(k)); i++) {
        if (k % i === 0)
            return false;
    }
    return true;
}

function solution(n) {
    //팰린드롬 만족하는것 찾고 -> 소수판별

    for (let i = n; ; i++) {
        if (isPalin(i)) {
            if (isPrime(i))
                return i;
        }
    }

}

console.log(solution(n));