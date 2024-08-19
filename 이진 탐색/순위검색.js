//[Lv2] 순위검색 https://school.programmers.co.kr/learn/courses/30/lessons/72412

function getCasesAndScore(row) {
    let cases = [];
    let score = +row[4];
    row = [
        [row[0], '-'],
        [row[1], '-'],
        [row[2], '-'],
        [row[3], '-'],
    ]
    for (let i = 0; i < row[0].length; i++) {
        for (let j = 0; j < row[1].length; j++) {
            for (let k = 0; k < row[2].length; k++) {
                for (let l = 0; l < row[3].length; l++) {
                    cases.push(`${row[0][i]}_${row[1][j]}_${row[2][k]}_${row[3][l]}`)
                }
            }
        }
    }
    return [cases, score]
}

function createCaseMap(info) {
    let caseMap = {};

    info.forEach((row) => {
        let [cases, score] = getCasesAndScore(row);
        cases.forEach((oneCase)=>{
            if(caseMap[oneCase]) {
                caseMap[oneCase].push(score);
            }
            else{
                caseMap[oneCase] = [score];
            }
        })
    })

    return caseMap;
}

function binarySearch(array, value){
    let left = 0;
    let right = array.length - 1;
    let mid
    
    while(left <= right){
        mid = Math.floor((left+right)/2);
        if(array[mid] < value){
            left = mid + 1
        }
        else{
            right = mid -1;
        }
    }
    return right;
}

function solution(info, query) {

    info = info.map((row) => row.split(' ')).sort((a,b)=>+a[4] - +b[4])
    query = query.map((row) => row.split(' ').filter((v) => v !== 'and'));

    var answer = [];
    const caseMap = createCaseMap(info);
    
    query.forEach((row)=>{
        let key = `${row[0]}_${row[1]}_${row[2]}_${row[3]}`;
        let target = caseMap[key];
        if(target){
            answer.push(target.length - binarySearch(target, +row[4]) - 1)
        }
        else{
            answer.push(0);
        }
    })

    return answer;
}

