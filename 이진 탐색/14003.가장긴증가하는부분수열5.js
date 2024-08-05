//[플레5] 14003.가장긴증가하는부분수열5 https://www.acmicpc.net/problem/14003

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let seq = input[1].split(' ').map((v)=>+v);

function binarySearch(arr, num){

    let left = 0;
    let right = arr.length-1;
    let mid;
    while(left <= right){
        mid = Math.floor((left+right)/2);
        if(arr[mid] === num){
            return mid;
        }
        else if(arr[mid] < num){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return left;

}

function solution(n, seq){

    let subseq = [seq[0]];
    let tracking = [[0, seq[0]]];

    for(let i=1;i<n;i++){
        if(subseq.at(-1) < seq[i]){
            subseq.push(seq[i]);
            tracking.push([subseq.length-1, seq[i]])
        }
        else{
            let targetIdx = binarySearch(subseq, seq[i]);
            subseq[targetIdx] = seq[i];
            tracking.push([targetIdx, seq[i]]);
        }
    }

    console.log(subseq.length);
    let idx = subseq.length-1;
    for(let i=tracking.length - 1; i>=0;i--){
        if(idx === tracking[i][0]){
            subseq[idx] = tracking[i][1];
            idx--;
        }
    }
    console.log(subseq.join(' '));

}

solution(n, seq);