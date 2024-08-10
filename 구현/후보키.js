//[Lv2] 후보키 https://school.programmers.co.kr/learn/courses/30/lessons/42890

function isSubset(subset, superset){
    for (let elem of subset) {
        if (!superset.has(elem)) {
            return false;
        }
    }
    return true;
}

function getCombinations(arr, selectNum){
    
    if(selectNum === 1){
        return arr.map((e)=>[e]);
    }
    
    let combinations = [];
    
    arr.forEach((fixed, index, origin)=>{
        let rest = origin.slice(index+1);
        let tmp = getCombinations(rest, selectNum-1);
        let attached = tmp.map((e) => [fixed, ...e])
        combinations.push(...attached);
    })
    
    return combinations;
    
}

function getCandidateKeys(colNum){
    let attributes = []
    let candidateKeys = [];
    for(let i = 0; i< colNum; i++){
        attributes.push(i);
    }
    for(let i = 0; i< colNum ; i++){
        let tmp = getCombinations(attributes, i+1);
        candidateKeys.push(...tmp.map((e) => new Set(e)));
    }
    return candidateKeys;
}

function solution(relation) {
    
    let colNum = relation[0].length;
    let rowNum = relation.length;
    let candidateKeys = getCandidateKeys(colNum);  //키가 되는 모든 경우의 수를 구함.
    let answer = [];
    
    candidateKeys.forEach((keys)=>{

        //keys = set(0,1) 이런경우에는 0번째 속성과 1번째 속성을 key로 하는 경우.
        
        let checkArr =[];
        relation.forEach((tuple, index)=>{
            let tmp =[] //여기에 relation에서 key 속성에 해당하는 값들만 모아서 배열을 만듦
            keys.forEach((j)=>{
                tmp.push(tuple[j]);
            })
            checkArr.push(tmp); //checkArr에 넣기
        })
        
        checkArr = new Set(checkArr.map(JSON.stringify)); //이걸로 이제 중복된 value가 있는지 확인
        
        if(checkArr.size === rowNum){ //tuple수랑, checkArr 크기랑 같으면 이제 유일성을 만족
            //최소성을 검사하자. answer에 있는 key들 중 부분집합이 되는게 있는지 확인하자.
            let flag = 0;
            for(let l = 0; l < answer.length; l++){
                if (isSubset(answer[l], keys)){
                    flag = 1;
                    break;
                }
            }
            if (flag === 0){ //부분집합이 아닌 경우에만 answer에 넣기
                answer.push(keys);
            }
        }
    })
    
    return answer.length;
}