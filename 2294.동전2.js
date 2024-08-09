//[골드5] 2294.동전2 https://www.acmicpc.net/problem/2294

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

// console.log(input);
let [n, k] = input[0].split(' ');
const coins = input.slice(1).map((e)=>+e);

function recur(value, coins, index){
    if (value < coins[index]){
        return -1;
    }

    let maxCoinNum = Math.floor(value / coins[index]);
    console.log(maxCoinNum);

    let coinNumArray = [];

    for(let i = maxCoinNum; i >= 0; i--){
        // console.log(value - i * coins[index]);
        let tmp = recur(value - i * coins[index], coins, index + 1);
        if(tmp !== -1){
            coinNumArray.push(tmp);
        }
    }

    return coinNumArray.length > 0 ? Math.min(coinNumArray): -1;

}

function solution(k, coins){
    coins.sort((a,b)=> b - a);

    console.log(recur(k, coins, 0));

}

solution(k, coins);