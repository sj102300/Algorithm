//[골드4] 2580.스도쿠 https://www.acmicpc.net/problem/2580

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

function printMap(map) {
    console.log(map.map((e) => e.join(" ")).join('\n'));
}

let answer = null;

function btrk(map, Xset, Yset, squareSet, emptySection, n, i) {
    if (answer !== null)
        return;
    if (n === i) {
        answer = [...map.map((v)=>[...v])];
        return;
    }

    let [x, y] = emptySection[i];

    let squareX = Math.floor(x / 3);
    let squareY = Math.floor(y / 3);

    let XsetArray = [...Xset[x]];

    for (let j=0;j<XsetArray.length;j++) {
        let key = XsetArray[j];
        if (Yset[y].has(key) && squareSet[squareX][squareY].has(key) && key !== undefined) {
            Xset[x].delete(key);
            Yset[y].delete(key);
            squareSet[squareX][squareY].delete(key);
            map[x][y] = key;
            btrk(map, Xset, Yset, squareSet, emptySection, n, i + 1);
            Xset[x].add(key);
            Yset[y].add(key);
            squareSet[squareX][squareY].add(key);
        }
    }

}

function solution(input) {

    let emptySection = [];

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (input[i][j] === 0) {
                emptySection.push([i, j]);
            }
        }
    }

    let defaults = [1, 2, 3, 4, 5, 6, 7, 8, 9];
    let Xset = Array.from({ length: 9 }, () => new Set(defaults));
    let Yset = Array.from({ length: 9 }, () => new Set(defaults));
    let squareSet = Array.from({ length: 3 }, () => Array.from({ length: 3 }, () => new Set(defaults)));

    emptySection.forEach(([x, y]) => {
        for (let i = 0; i < 9; i++) {
            Xset[x].delete(input[x][i]);
            Yset[y].delete(input[i][y]);
        }
        let squareX = Math.floor(x / 3);
        let squareY = Math.floor(y / 3);
        for (let a = squareX * 3; a < squareX * 3 + 3; a++) {
            for (let b = squareY * 3; b < squareY * 3 + 3; b++) {
                squareSet[squareX][squareY].delete(input[a][b]);
            }
        }
    })

    btrk(input, Xset, Yset, squareSet, emptySection, emptySection.length, 0);

    printMap(answer);
}

solution(input);