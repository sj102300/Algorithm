//[Lv2] 도넛과막대그래프 https://school.programmers.co.kr/learn/courses/30/lessons/258711

function solution(edges) {
    var answer = [0,0,0,0];
    
    let graph = Array.from({length: 1000001}, ()=>{return {in: 0, out: 0}});
    let maxVertex = 0;
    
    edges.forEach((edge)=>{
        maxVertex = Math.max(maxVertex, edge[0], edge[1]);
        (graph[edge[0]].out)++;
        (graph[edge[1]].in)++;
    })
    graph = graph.slice(1, maxVertex+1);
    
    answer[0] = graph.findIndex((v)=> v.out >= 2 && v.in === 0) + 1
    
    answer[2] = graph.filter((v)=> v.in !== 0 && v.out == 0).length;
    
    answer[3] = graph.filter((v)=> v.in >=2 && v.out ===2).length;
    
    answer[1] = graph[answer[0]-1].out - answer[2] - answer[3];
    
    
    return answer;
}