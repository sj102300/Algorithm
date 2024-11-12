//[골드2] 19238.스타트택시 https://www.acmicpc.net/problem/19238

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let [N, M, fuel] = input.shift();
let map = input.splice(0, N);
let taxi = input.shift().map((v) => v - 1);
let customers = new Map();

for (let i = 0; i < M; i++) {
    let [startX, startY, destX, destY] = input[i].map((v) => v - 1);
    customers.set(`${startX} ${startY}`, `${destX} ${destY}`);
}

function initVisited(visited, n) {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            visited[i][j] = Infinity;
        }
    }
}

function BFS(map, visited, start, n) {

    initVisited(visited, n);
    let queue = [start];
    let front = 0;
    visited[start[0]][start[1]] = 0;

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    while (front < queue.length) {
        let first = queue[front++];

        for (let i = 0; i < 4; i++) {
            let newX = first[0] + dx[i];
            let newY = first[1] + dy[i];
            if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                continue;
            if (visited[newX][newY] > visited[first[0]][first[1]] + 1 && map[newX][newY] === 0) {
                visited[newX][newY] = visited[first[0]][first[1]] + 1;
                queue.push([newX, newY]);
            }
        }
    }
}

function solution(N, M, fuel, map, taxi, customers) {

    let visited = Array.from({ length: N }, () => Array(N).fill(Infinity));

    while (customers.size > 0) {
        BFS(map, visited, taxi, N);

        let targetCustomerLocation;
        let targetLength = Infinity;
        let destinationLocation;

        for(let [customerLocation, destination] of customers){
            let [custX, custY] = customerLocation.split(" ").map((e)=>+e);
            if(visited[custX][custY] !== Infinity &&
                (targetLength > visited[custX][custY] ||
                (targetLength === visited[custX][custY] && custX < targetCustomerLocation[0]) || 
                (targetLength === visited[custX][custY] && custX === targetCustomerLocation[0] && custY < targetCustomerLocation[1])))
                {
                targetLength = visited[custX][custY];
                targetCustomerLocation = [custX, custY];
                destinationLocation = destination.split(" ").map((e)=>+e);
            }
        }

        if(targetLength === Infinity || fuel < targetLength){ //손님을 데리러 못감 연료 부족
            return -1;
        }

        fuel -= targetLength;
        taxi = targetCustomerLocation;
        
        BFS(map, visited, taxi, N);
        let startToDestLength = visited[destinationLocation[0]][destinationLocation[1]];

        if(startToDestLength === Infinity || fuel < startToDestLength){  //손님을 목적지까지 못데려다 줌 연료 부족
            return -1;
        }

        customers.delete(`${targetCustomerLocation[0]} ${targetCustomerLocation[1]}`);  //데려다 주기 성공
        fuel -= startToDestLength;
        fuel += 2 * startToDestLength;
        taxi = destinationLocation;

    }

    //남은 연료양 반환
    return fuel;
}

console.log(solution(N, M, fuel, map, taxi, customers));