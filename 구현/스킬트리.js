//[Lv2] 스킬트리 https://school.programmers.co.kr/learn/courses/30/lessons/49993

function solution(skill, skill_trees) {
    var answer = skill_trees.length;
    
    const skillset = new Set(skill.split(''));
    
    skill_trees.forEach((skillTree)=>{
        let tree = skillTree.split('');
        let tmp = [];
        tree.forEach((v)=>{
            if(skillset.has(v)){
                tmp.push(v);
            }
        })
        
        for(let i=0;i<tmp.length;i++){
            if(skill[i] !== tmp[i]){
                answer--;
                break;
            }
        }
    })
    
    return answer;
}