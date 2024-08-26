//[브론즈1] 2609.최대공약수와최대공배수 https://www.acmicpc.net/problem/2609

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [a, b] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((V) => +V);

//Greatest Common Divisor, 최대공약수
//a를 b로 나눈 나머지를 r이라할때, (a>b) a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
//gcd(a,b) = gcd(b, a%b);
function gcd(a, b) {
    if (a % b === 0)
        return b;
    else
        return gcd(b, a % b);
}

//Least Common Muliple, 최소공배수
function lcm(a, b) {
    return a * b / gcd(a, b);
}

function solution(a, b) {

    let [max, min] = a > b ? [a, b] : [b, a];

    console.log(gcd(max, min));
    console.log(lcm(max, min));

}

solution(a, b);