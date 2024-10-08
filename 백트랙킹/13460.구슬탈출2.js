//[골드1] 13460.구슬탈출2 https://www.acmicpc.net/problem/13460

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input.shift().split(' ').map((v) => +v);
let map = input.map((v) => v.split(''));

let answer = 11;

//하 우 상 좌
const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function getMarbleLocation(N, M, map) {
    let originalRed, originalBlue, hole;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (map[i][j] === 'R') {
                originalRed = [i, j];
            }
            else if (map[i][j] === 'B') {
                originalBlue = [i, j];
            }
            else if (map[i][j] === 'O') {
                hole = [i, j];
            }
        }
    }
    return { originalRed, originalBlue, hole };
}

const { originalRed, originalBlue, hole } = getMarbleLocation(N, M, map);


function moveMarble(map, marble, dir) { //frist -> 첫번째로 움직일 구슬, second ->두번째로 움직일 구슬

    let isStopped = false;

    while (!isStopped) {
        let newX = marble[0] + dx[dir];
        let newY = marble[1] + dy[dir];

        if (map[newX][newY] === '.') {
            [map[newX][newY], map[marble[0]][marble[1]]] = [map[marble[0]][marble[1]], map[newX][newY]];
            marble = [newX, newY];
        }
        else if(map[newX][newY] === 'O'){
            //구멍에 들어갔음
            map[marble[0]][marble[1]] = '.';
            marble = [newX, newY];
            isStopped = true;
        }
        else {
            isStopped = true;
        }
    }

    return marble;

}

function btrk(n, history) {

    if (n === 10) {
        //종료조건
        let newMap = map.map((v) => [...v]);
        let red = [...originalRed];
        let blue = [...originalBlue];
        for(let i=0;i<history.length;i++){
            let dir = history[i]
            if (dir === 0) {
                if (red[0] > blue[0]) {
                    red = moveMarble(newMap, red, dir);
                    blue = moveMarble(newMap, blue, dir);
                }
                else {
                    blue = moveMarble(newMap, blue, dir);
                    red = moveMarble(newMap, red, dir);
                }
            }
            else if (dir === 1) {
                if (red[1] > blue[1]) {
                    red = moveMarble(newMap, red, dir);
                    blue = moveMarble(newMap, blue, dir);
                }
                else {
                    blue = moveMarble(newMap, blue, dir);
                    red = moveMarble(newMap, red, dir);
                }
            }
            else if (dir === 2) {
                if (red[0] < blue[0]) {
                    red = moveMarble(newMap, red, dir);
                    blue = moveMarble(newMap, blue, dir);
                }
                else {
                    blue = moveMarble(newMap, blue, dir);
                    red = moveMarble(newMap, red, dir);
                }
            }
            else if (dir === 3) {
                if (red[1] < blue[1]) {
                    red = moveMarble(newMap, red, dir);
                    blue = moveMarble(newMap, blue, dir);
                }
                else {
                    blue = moveMarble(newMap, blue, dir);
                    red = moveMarble(newMap, red, dir);
                }
            }
            if (blue[0] === hole[0] && blue[1] === hole[1]) { //파란색구슬이 들어가버림
                break;
            }
            if (red[0] === hole[0] && red[1] === hole[1]) {
                answer = Math.min(i+1, answer);
                break;
            }
        }
        return;
    }

    if (history[history.length - 1] % 2 === 0) {
        btrk(n + 1, [...history, 1]);
        btrk(n + 1, [...history, 3]);
    }
    else {
        btrk(n + 1, [...history, 0]);
        btrk(n + 1, [...history, 2]);
    }

}



function solution(N, M, map) {

    btrk(1, [0])
    btrk(1, [1])
    btrk(1, [2])
    btrk(1, [3])

    // btrk(0, [])

    return answer === 11 ? -1 : answer;
}

console.log(solution(N, M, map))
