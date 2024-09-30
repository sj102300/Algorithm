//[골드2] 1918.후위표기식 https://www.acmicpc.net/problem/1918

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('');

function solution(input) {

    let priority = {
        '*': 2,
        '/': 2,
        '+': 1,
        '-': 1,
    }

    //스택으로 사용
    let operator = [];

    let answer = '';

    let pointer = 0;
    while (pointer < input.length) {
        if (input[pointer] === '(') {
            operator.push(input[pointer]);
        }
        else if (input[pointer] === ')') {
            let top = operator.pop();
            while (top !== '(') {
                answer += top;
                top = operator.pop();
            }
        }
        else if (input[pointer] === '*' || input[pointer] === '/' || input[pointer] === '+' || input[pointer] === '-') {
            while (priority[operator.at(-1)] >= priority[input[pointer]]) {
                let top = operator.pop();
                answer += top;
            }
            operator.push(input[pointer]);
        }
        else {
            answer += input[pointer];
        }

        pointer++;
    }

    while (operator.length) {
        let top = operator.pop();
        answer += top;
    }

    return answer;

}

console.log(solution(input));