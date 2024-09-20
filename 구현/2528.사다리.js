//[골드3] 2528.사다리 https://www.acmicpc.net/problem/2528

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(' ').map((e) => +e))

const [N, L] = input.shift();

function canGoUp(arrange, floor){
    if(arrange[floor][1] < arrange[floor+1][0] || arrange[floor][0] > arrange[floor+1][1])
        return false;
    return true;
}

function solution(N, L, input) {

    let dir = input.map((v)=>v[1]);

    let arrange = input.map((v)=>v[1] === 0 ? [0, v[0]]: [L-v[0], L] );

    let floor = 0;
    let time = 0;

    while(floor < N - 1){
        if(canGoUp(arrange, floor)){
            floor++;
        }
        else{
            time++;
            for(let i=0;i<arrange.length;i++){
                if(dir[i] === 0){
                    if(arrange[i][0] === L){
                        arrange[i][0]--;
                        arrange[i][1]--;
                        dir[i]=1;
                    }
                    else{
                        arrange[i][0]++;
                        arrange[i][1]++;
                    }
                }
                else{
                    if(arrange[i][0] === 0){
                        arrange[i][0]++;
                        arrange[i][1]++;
                        dir[i] = 0;
                    }
                    else{
                        arrange[i][0]--;
                        arrange[i][1]--;
                    }
                }
            }
        }
    }

    return time;

}

console.log(solution(N, L, input));