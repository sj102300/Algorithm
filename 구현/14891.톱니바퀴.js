//[골드5] 14891.톱니바퀴 https://www.acmicpc.net/problem/14891

import { createRequire } from "module";
const require = createRequire(import.meta.url)

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let wheels = input.splice(0, 4).map((v) => v.split(''));

let k = +(input.shift())
let rotation = input.map((v) => v.split(' ').map((e) => +e))

function rotate(wheel, direction) {

    if (direction === 1) { //시계방향
        let tmp = wheel.at(-1);
        return [tmp, ...wheel.slice(0, wheel.length-1)]
    }
    else { //반시계방향
        let tmp = wheel[0];
        return [...wheel.slice(1), tmp]
    }
}

function solution(wheels, k, rotation) {

    let newWheels
    rotation.forEach(([target, direction]) => {
        target--;
        newWheels = [...wheels];
        newWheels[target] = rotate(wheels[target], direction);

        let d = direction;
        for (let i = target + 1; i < 4; i++) {  //오른쪽 먼저 돌리기
            if (wheels[i][6] !== wheels[i - 1][2]) {
                d = -d;
                newWheels[i] = rotate(wheels[i], d);
            }
            else {
                break;
            }
        }
        d = direction;
        for (let i = target - 1; i >= 0; i--) {
            if (wheels[i][2] !== wheels[i + 1][6]) {
                d = -d;
                newWheels[i] = rotate(wheels[i], d);
            }
            else {
                break;
            }
        }
        wheels = newWheels
    })

    let answer = 0;

    for (let i = 0; i < 4; i++) {
        if (wheels[i][0] === '1') {
            answer += Math.pow(2, i);
        }
    }

    return answer;

}

console.log(solution(wheels, k, rotation))