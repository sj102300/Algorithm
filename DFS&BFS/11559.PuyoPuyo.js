//[골드4] 11559.PuyoPuyo https://www.acmicpc.net/problem/11559

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(''));

const X = 12;
const Y = 6;

const dx = [0, 1, 0, -1];
const dy = [1, 0, -1, 0];

function DFS(map, visited, start) {

    if (visited[start[0]][start[1]]) return [];
    visited[start[0]][start[1]] = true;
    if (map[start[0]][start[1]] === '.') return [];

    let result = [start];
    for (let i = 0; i < 4; i++) {
        let newX = start[0] + dx[i];
        let newY = start[1] + dy[i];
        if (newX < 0 || newY < 0 || newX >= X || newY >= Y)
            continue;
        if (map[newX][newY] === '.')
            continue;
        if (map[start[0]][start[1]] === map[newX][newY]) {
            result.push(...DFS(map, visited, [newX, newY]));
        }
    }
    return result;
}

function initVisited(visited) {
    for (let i = 0; i < X; i++) {
        for (let j = 0; j < Y; j++) {
            visited[i][j] = false;
        }
    }
}

function downPuyo(map) {
    for (let j = 0; j < Y; j++) {
        let bottom = X -1;
        for (let i = X - 1; i >= 0; i--) {
            if (map[i][j] !== '.') {
                map[bottom--][j] = map[i][j];
            }
        }
        for( ; bottom >=0;){
            map[bottom--][j]= '.';
        }
    }
}

function printMap(map) {
    console.log(map.map((v) => v.join('')).join('\n'));
}

function solution(input) {


    let visited = Array.from({ length: X }, () => Array.from({ length: Y }, () => false));
    let partition = [];
    let answer = 0;

    while (true) {

        // printMap(input);
        // console.log('------')
        for (let i = 0; i < X; i++) {
            for (let j = 0; j < Y; j++) {
                let tmp = DFS(input, visited, [i, j]);
                if (tmp.length >= 4) {
                    partition.push(tmp);
                }
            }
        }

        if(partition.length === 0)
            break;

        partition.forEach((part) => {
            part.forEach((node) => {
                input[node[0]][node[1]] = '.'
            })
        })

        answer++;
        downPuyo(input);
        initVisited(visited);
        partition = [];

    }
    return answer;

}

console.log(solution(input));


//DFS로 -> 같은 색깔끼리 구역 나누기
//구역 크기가 4이상 -> 터뜨리기, 연쇄 +1, 
//맵 빈칸 채우기 (터진 뿌요의 빈자리 채우기)
//다시 visited초기화 하고 구역 나누기
//구역 크기가 4이상인거 없을때까지 반복