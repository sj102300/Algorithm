//[Lv3] 불량사용자 https://school.programmers.co.kr/learn/courses/30/lessons/64064

function checkId(userId, bannedId){
    
    for(let i=0; i < userId.length; i++){
        let user_id = userId[i];
        let banned_id = bannedId[i];
        
        if (user_id.length !== banned_id.length){
            return false;
        }
    
        for(let j=0; j<banned_id.length;j++){
            if(user_id[j] !== banned_id[j] && '*' !== banned_id[j]){
                return false;
            }
        }
    }
    
    return true;
}

function getPermutation(arr, n){
    let results = [];

    if (n === 1) {
        return arr.map((e)=>[e]);
    }
    
    arr.forEach((fixed, index, origin) =>{
        let rest = [...origin.slice(0, index),...origin.slice(index + 1)];
        let restPermutation = getPermutation(rest, n-1);
        let attached = restPermutation.map((e) => [fixed, ...e]);
        results.push(...attached);
    })
    
    return results;
}

function solution(user_id, banned_id) {
    
    var answer = [];
    
    let permutation = getPermutation(user_id, banned_id.length);
    let sortedBannedId = banned_id.sort((a,b) => a.length - b.length);
    
    permutation.forEach((e)=>{
        let sortedUserId = e.sort((a,b)=> a.length - b.length);
        if(checkId(sortedUserId, sortedBannedId)){
            answer.push(e);
        }
    })
    
    let set = [...new Set(answer.map((v)=>v.sort().join(' ')))]
    
    return set.length;
}