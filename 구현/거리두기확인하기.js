//[Lv2] 거리두기확인하기 https://school.programmers.co.kr/learn/courses/30/lessons/81302

function isValidPlace(place){
    
    let move1 = {
        dx:[1,0,-1,0],
        dy:[0,1,0,-1]
    }
    
    let move2 = {
        dx : [2,0,-2,0],
        dy: [0,2,0,-2],
        partitionX: [1,0,-1,0],
        partitionY: [0,1,0,-1]
    }
    
    let move3 = {
        dx: [1,1,-1,-1],
        dy: [1,-1,1,-1]
    }
    
    let newX, newY, partitionX, partitionY, secondPartitionX, secondPartitionY;
    for(let i=0;i<place.length;i++){
        for(let j=0;j<place[i].length;j++){
            if(place[i][j] === 'P'){
                
                for(let k=0;k<4;k++){
                    newX = i+move1.dx[k];
                    newY = j+move1.dy[k];
                    if(newX < 0 || newX >= place.length || newY < 0 || newY >= place[i].length){
                        continue;
                    }
                    if(place[newX][newY] === 'P'){
                        return false;
                    }
                }
                
                for(let k=0; k<4; k++){
                    newX = i+move2.dx[k];
                    newY = j+move2.dy[k];
                    partitionX = i + move2.partitionX[k];
                    partitionY = j+move2.partitionY[k];
                    if(newX < 0 || newX >= place.length || newY < 0 || newY >= place[i].length){
                        continue;
                    }
                    if(place[newX][newY] === 'P' && place[partitionX][partitionY] !=='X'){
                        return false
                    }
                }
                
                for(let k=0;k<4;k++){
                    newX = i+move3.dx[k];
                    newY = j+move3.dy[k];
                    if(newX < 0 || newX >= place.length || newY < 0 || newY >= place[i].length){
                        continue;
                    }
                    partitionX = i+move3.dx[k];
                    partitionY = j;
                    secondPartitionX = i;
                    secondPartitionY = j+move3.dy[k];
                    if(place[newX][newY] === 'P' && 
                      (place[partitionX][partitionY] !== 'X' ||
                      place[secondPartitionX][secondPartitionY] !== 'X')){
                        return false;
                    }
                }

            }
        }
    }
    
    return true;
}

function solution(places) {
    var answer = [];
    
    places.forEach((place)=>{
        if(isValidPlace(place)){
            answer.push(1);
        }
        else{
            answer.push(0);
        }
    })
    
    return answer;
}