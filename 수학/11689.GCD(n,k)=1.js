//[골드1] 11689.GCD(n,k)=1 https://www.acmicpc.net/problem/11689

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = BigInt(+(fs.readFileSync('dev/stdin', 'utf-8').trim()));

//1~n까지의 범위에서 n과 서로소인 자연수의 개수를 찾음
//서로소 = 최대공약수가 1인 것
function eulerPhi(n) {
    let result = n;
    let p = 2;
    
    // n의 소인수들을 찾고 오일러 피 함수 계산
    while (p * p <= n) {
        // n이 p로 나누어 떨어지면 p는 n의 소인수
        if (n % p === 0) {
            // p로 나눌 수 있을 때마다 n을 나눠줌
            while (n % p === 0) {
                n = Math.floor(n / p);
            }
            // 오일러 피 함수 공식 적용
            result -= Math.floor(result / p);
        }
        p++;
    }
    
    // 남은 n이 1보다 크다면 이는 소수
    if (n > 1) {
        result -= Math.floor(result / n);
    }
    
    return result;
}

function solution(n) {
    return eulerPhi(n);
}
console.log(solution(input));