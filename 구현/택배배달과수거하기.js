//[Lv2] 택배배달과수거하기 https://school.programmers.co.kr/learn/courses/30/lessons/150369

function solution(cap, n, deliveries, pickups) {
    var answer = 0;
    
    let i = n - 1;
    let j = n - 1;
    while (i >= 0 || j >= 0) {
        let curDeliveries = 0;
        let curPickups = 0;
        
        let lastDeliveries = -1;
        let lastPickups = -1;
        
        let k = i;
        while(k>=0){
            if (curDeliveries === 0 && deliveries[k] !== 0){
                lastDeliveries = k;
            }
            if(curDeliveries + deliveries[k] <= cap){
                curDeliveries += deliveries[k];
                k--;
            }
            else {
                deliveries[k] -= (cap - curDeliveries)
                curDeliveries = cap
            }
            if (curDeliveries === cap || k < 0){
                i = k;
                break;
            }
        }
        
        let l = j;
        while(l>=0){
            if (curPickups === 0 && pickups[l] !==0){
                lastPickups = l;
            }
            if(curPickups + pickups[l] <= cap){
                curPickups += pickups[l];
                l--;
            }
            else {
                pickups[l] -= (cap - curPickups);
                curPickups = cap;
            }
            if(curPickups === cap || l < 0){
                j = l;
                break;
            }
        }

        answer += (lastDeliveries+1) > (lastPickups+1) ? (lastDeliveries + 1) * 2 : (lastPickups + 1) * 2;
    }

    console.log(answer);
    
    return answer;
}

solution(  1, 5, [0, 0, 1, 0, 0], [0, 0, 0, 0, 0]);