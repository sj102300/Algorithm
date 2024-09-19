//[골드3] 19591.독특한계산기 https://www.acmicpc.net/problem/19591

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim();

function parseInput(operand, operator, input) {

    let tmp = '';
    for (let i = 0; i < input.length; i++) {
        if (i === 0 && input[i] === '-') {  //문자열 맨처음에 음수가 들어오는 경우 처리
            tmp += input[i];
        }
        else if (input[i] === '+' || input[i] === '-' || input[i] === '*' || input[i] === '/') {
            operand.push(BigInt(tmp));
            tmp = '';
            operator.push(input[i]);
        }
        else {
            tmp += input[i];
        }
    }
    operand.push(BigInt(tmp));
    return;
}

function calc(target) {
    let [a, b, op] = target;

    if (op === '+')
        return a + b;
    else if (op === '-')
        return a - b;
    else if (op === '*')
        return a * b;
    else if (op === '/')
        if (a * b > 0)
            return a / b;
        else
            return -(-a / b);
}

function solution(input) {

    const operand = [];
    const operator = [];

    parseInput(operand, operator, input);

    let startIdx = 0;
    let endIdx = operand.length - 1;

    while (startIdx < endIdx) {
        let left = [operand[startIdx], operand[startIdx + 1], operator[startIdx]];
        let right = [operand[endIdx - 1], operand[endIdx], operator[endIdx - 1]];

        let leftResult = calc(left);
        let rightResult = calc(right);
        if ((left[2] === '*' || left[2] === '/') && !(right[2] === '*' || right[2] === '/')) {
            operand[++startIdx] = leftResult;
        }
        else if (!(left[2] === '*' || left[2] === '/') && (right[2] === '*' || right[2] === '/')) {
            operand[--endIdx] = rightResult;
        }
        else {
            if (leftResult >= rightResult) {
                operand[++startIdx] = leftResult;
            }
            else {
                operand[--endIdx] = rightResult;
            }
        }
    }

    return '' + operand[startIdx];

}

console.log(solution(input));