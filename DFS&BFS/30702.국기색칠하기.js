//[실버1] 30702.국기색칠하기 https://www.acmicpc.net/problem/30702

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input[0].split(' ').map((v) => +v);

let A = input.slice(1, 1 + N);
let B = input.slice(1 + N);

function getSubA(A, visitedA, start) {

    if (visitedA[start[0]][start[1]] === true)
        return [];

    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    visitedA[start[0]][start[1]] = true;

    let subA = [[start[0], start[1]]];

    for (let i = 0; i < 4; i++) {
        let newX = start[0] + dx[i];
        let newY = start[1] + dy[i];
        if (newX < 0 || newY < 0 || newX >= N || newY >= M)
            continue;
        if (A[newX][newY] !== A[start[0]][start[1]]) {
            continue;
        }
        let tmp = getSubA(A, visitedA, [newX, newY]);
        if (tmp.length !== 0) {
            subA.push(...tmp)
        }
    }

    return subA;
}

function solution(N, M, A, B) {

    let visitedA = Array.from({ length: N }, () => Array(M).fill(false));
    let answer = 'YES';

    let subA = []
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            let tmp = getSubA(A, visitedA, [i, j]);
            if (tmp.length !== 0) {
                subA.push(tmp)
            }
        }
    }

    subA.forEach((subPart) => {
        let targetColor = B[subPart[0][0]][subPart[0][1]];
        for (let i = 1; i < subPart.length; i++) {
            if (B[subPart[i][0]][subPart[i][1]] !== targetColor) {
                answer = 'NO';
                return false;  //break하기위함
            }
        }
    })

    return answer;
}

console.log(solution(N, M, A, B));