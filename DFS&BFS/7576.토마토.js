//[골드5] 7576.토마토 https://www.acmicpc.net/problem/7576

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [M, N] = input.shift().split(' ').map((v) => +v);
let map = input.map((v) => v.split(' ').map((e) => +e));

function solution(M, N, map) {

    let queue = []; //0번째 날에 익은 토마토
    for(let i=0;i<N;i++){
        for(let j=0;j<M;j++){
            if(map[i][j] === 1){
                queue.push([i,j]);
            }
        }
    }

    const dx =[1,0,-1,0];
    const dy = [0,1,0,-1];

    let time = -1;

    while(queue.length){
        let tmpQueue = []; //다음날 익을 토마토들

        time++;
        queue.forEach(([a,b])=>{  //time번째 날에 토마토 익히기.. 
            for(let dir=0;dir<4;dir++){
                let newX = a + dx[dir];
                let newY = b + dy[dir];
                if(newX < 0 || newY<0 || newX>=N || newY >=M)
                    continue;
                if(map[newX][newY] === 0){
                    tmpQueue.push([newX, newY]);
                    map[newX][newY] = 1;
                }
            }
        })

        queue = tmpQueue;
    }

    
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            if (map[i][j] === 0) {
                return -1;
            }
        }
    }
    return time;
}

console.log(solution(M, N, map));
