//[Lv2] 퍼즐게임챌린지 https://school.programmers.co.kr/learn/courses/30/lessons/340212

import java.util.*;

class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        
        int left = Arrays.stream(diffs).min().getAsInt();
        int right = Arrays.stream(diffs).max().getAsInt();
        
        while(left < right){
            int level = (int)Math.floor((left+right)/2);
            
            long neededTime = 0;
            long prevTime = 0;
            
            for(int i=0;i<diffs.length;i++){
                if(diffs[i] <= level){
                    neededTime += times[i];
                }
                else {
                    neededTime += (diffs[i] - level) * (prevTime + times[i]) + times[i];
                }
                prevTime = times[i];
            }
            
            if(neededTime < limit){
                right = level;
            }
            else if(neededTime > limit){
                left = level + 1;
            }
            else{
                left = level;
                break;
            }
        }
        return left;
    }
}