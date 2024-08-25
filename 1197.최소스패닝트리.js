//[골드4]  1197.최소스패닝트리 https://www.acmicpc.net/problem/1197

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [V, E] = input[0].split(' ').map((v)=>+v);
