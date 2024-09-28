//[실버5] 10709.기상캐스터 https://www.acmicpc.net/problem/10709

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [H, W] = input.shift().split(' ').map((V) => +V);

function solution(H, W, map) {

    let result = Array.from({ length: H }, () => Array.from({ length: W }, () => -1));

    for (let i = 0; i < H; i++) {
        let time=-1;
        for (let j = 0; j < W; j++) {
            if(map[i][j] === 'c'){
                time=0;
                result[i][j] = time;
            }
            else{
                if(time !== -1){
                    result[i][j] = ++time;
                }
            }
        }
    }
    return result.map((v)=>v.join(' ')).join('\n');

}

console.log(solution(H, W, input));