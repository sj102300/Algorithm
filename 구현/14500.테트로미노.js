//[골드4] 14500.테트로미노 https://www.acmicpc.net/problem/14500

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input.shift().split(' ').map((V) => +V);
let map = input.map((v) => v.split(' ').map((e) => +e));

function solution(N, M, map) {

    const tetromino = [
        [[1, 1, 1, 1]], [[1], [1], [1], [1]],
        [[1, 1], [1, 1]],
        [[1, 1, 1], [1, 0, 0]], [[1, 1, 1], [0, 0, 1]],
        [[1, 0, 0], [1, 1, 1]], [[0, 0, 1], [1, 1, 1]],
        [[1, 0], [1, 0], [1, 1]], [[0, 1], [0, 1], [1, 1]],
        [[1, 1], [1, 0], [1, 0]], [[1, 1], [0, 1], [0, 1]],
        [[1, 0], [1, 1], [0, 1]], [[0, 1], [1, 1], [1, 0]],
        [[1, 1, 0], [0, 1, 1]], [[0, 1, 1], [1, 1, 0]],
        [[1, 0], [1, 1], [1, 0]], [[0, 1], [1, 1], [0, 1]],
        [[0, 1, 0], [1, 1, 1]], [[1, 1, 1], [0, 1, 0]],
    ]

    let answer = 0;

    tetromino.forEach((block) => {
        for (let i = 0; i <= N - block.length; i++) {
            for (let j = 0; j <= M - block[0].length; j++) {
                //여기서 블록별 합 계산
                let blockSum = 0;
                for (let a = 0; a < block.length; a++) {
                    for (let b = 0; b < block[0].length; b++) {
                        if(block[a][b] === 1){
                            blockSum += map[a+i][b+j]
                        }
                    }
                }
                if (blockSum > answer) {
                    answer = blockSum;
                }
            }
        }
    })

    return answer;

}

console.log(solution(N, M, map));
