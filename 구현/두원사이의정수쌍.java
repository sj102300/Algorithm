//[Lv2] 두원사이의정수쌍 https://school.programmers.co.kr/learn/courses/30/lessons/181187

class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        
        for(int i=1 ;i<=r2;i++){
            
            int maxY = (int)Math.floor(Math.sqrt(Math.pow(r2,2) - Math.pow(i,2)));
            int minY = (int)Math.ceil(Math.sqrt(Math.pow(r1,2) - Math.pow(i,2)));
            
            answer += maxY - minY + 1;
            
        }
        
        return answer * 4;
    }
}