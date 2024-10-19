//[실버2] 1182.부분수열의합 https://www.acmicpc.net/problem/1182

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, S] = input[0].split(' ').map((v) => +v);
let data = input[1].split(' ').map((V) => +V);

let answer = 0;

function btrk(n, sum, cnt) {
    //[1] 종료조건(기저조건) : n에 관련된것.
    if (n == N) {
        //정답처리 관련 => 여기서. 중간에 정답처리를 할 수는 있지만, 최대한 여기서 하려고하자. 에러방지
        if (cnt > 0 && sum === S) //크기가 양수인 부분집합(1개이상)
            answer++;
        return;
    }

    btrk(n + 1, sum + data[n], cnt + 1); //n번째수를 선택하는 경우
    btrk(n + 1, sum, cnt);  //선택하지 않는 경우
}

btrk(0, 0, 0);
console.log(answer);