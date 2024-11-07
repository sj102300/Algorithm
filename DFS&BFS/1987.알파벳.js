//[골드4] 1987.알파벳 https://www.acmicpc.net/problem/1987

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [R, C] = input.shift().split(" ").map((v) => +v);

let answer = 0;

function DFS(map, start, visitedAlphabet, R, C, visitedAlphabetNum) {

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];
    let alphabet = map[start[0]][start[1]];
    visitedAlphabet[alphabet.charCodeAt(0) - 65] = true;
    visitedAlphabetNum++;

    if (visitedAlphabetNum > answer)
        answer = visitedAlphabetNum

    for (let i = 0; i < 4; i++) {
        let newX = start[0] + dx[i];
        let newY = start[1] + dy[i];
        if (newX < 0 || newY < 0 || newX >= R || newY >= C)
            continue;
        if (!visitedAlphabet[map[newX][newY].charCodeAt(0) - 65]) {
            DFS(map, [newX, newY], visitedAlphabet, R, C, visitedAlphabetNum);
        }
    }

    visitedAlphabet[alphabet.charCodeAt(0) - 65] = false;

}

let visitedAlphabet = Array(26).fill(false);

DFS(input, [0, 0], visitedAlphabet, R, C, 0);

console.log(answer);