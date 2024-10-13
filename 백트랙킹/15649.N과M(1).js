//[실버3] 15649.N과M https://www.acmicpc.net/problem/15649

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [N, M] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

let visited = Array(N+1).fill(0);
let answer = [];

function btrk(n, slst){
    //[1] 종료조건(기저조건) : n에 관련된것.
    if(n == M){
        //정답처리 관련 => 여기서!!
        answer.push(slst)
        return;
    }

    for(let j=1;j<=N;j++){
        //이미 사용한 숫자라면 안됨
        if (visited[j] === 0) {
            visited[j] = 1;
            btrk(n+1, [...slst, j]);
            visited[j] = 0; //반드시 원상복구
        }
    }
}

function solution(N, M) {

    //메인에서는 백트랙킹함수 한번만 호출
    btrk(0, []);

    return answer.map((v)=>v.join(' ')).join('\n');

}

console.log(solution(N, M));