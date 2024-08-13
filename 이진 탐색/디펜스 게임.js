//[Lv2] 디펜스게임 https://school.programmers.co.kr/learn/courses/30/lessons/142085

function solution(n, k, enemy) {
    
    let [left, right] = [0, enemy.length];
    
    while(left <= right){
        let mid = Math.floor((left + right) / 2);
        let tmp = enemy.slice(0, mid).sort((a,b) => b-a);
        let noDie = k
        let usedEnemys = tmp.reduce((acc, cur)=>{
            if (noDie > 0){
                noDie--;
                return acc
            }
            return acc + cur
        }, 0)
        if (n-usedEnemys >=0 && noDie >= 0){
            left = mid + 1
        }
        else{
            right = mid - 1
        }
    }
    
    return left - 1;
}