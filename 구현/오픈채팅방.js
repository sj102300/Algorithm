//[Lv2] 오픈채팅방 https://school.programmers.co.kr/learn/courses/30/lessons/42888

function solution(record) {
    
    let records = record.map((element) => element.split(" "));    
    let users = new Map([])
//     {
//         uid: uid,
//         nickName: "muzi",
//     }
    
    records.map((record)=>{
        if(record[0] === 'Enter' || record[0] === 'Change'){
            users.set(record[1], record[2]);
        }
    })
    
    let answer = []
    records.map((record)=>{
        if(record[0] === 'Enter'){
            answer.push(`${users.get(record[1])}님이 들어왔습니다.`);
        }
        else if(record[0] === 'Leave'){
            answer.push(`${users.get(record[1])}님이 나갔습니다.`);
        }
    })
    return answer;
}