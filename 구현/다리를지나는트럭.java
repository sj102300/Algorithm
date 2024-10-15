//[Lv2] 다리를지나는트럭 https://school.programmers.co.kr/learn/courses/30/lessons/42583

import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        int leftTime = bridge_length;  //현재 다리위의 
        Queue<Integer> truckQueue = new LinkedList<>();
        Queue<Integer> endTimeQueue = new LinkedList<>();
        Queue<Integer> curTruckInBridge = new LinkedList<>();
        
        for(int i=0;i<truck_weights.length;i++){
            truckQueue.add(truck_weights[i]);
        }
        
        int cur = 0;
        
        while(!truckQueue.isEmpty() || !endTimeQueue.isEmpty()){
            answer++;
            if(!endTimeQueue.isEmpty() && answer == endTimeQueue.peek()){
                endTimeQueue.poll();
                cur -= curTruckInBridge.poll();
            }
            if(!truckQueue.isEmpty() && cur + truckQueue.peek() <= weight){
                int target = truckQueue.poll();
                cur += target;
                curTruckInBridge.add(target);
                endTimeQueue.add(answer + bridge_length);
            }
        }
        
        return answer;
    }
}