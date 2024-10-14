//[Lv3] n+1카드게임 https://school.programmers.co.kr/learn/courses/30/lessons/258707

import java.util.*;

class Solution {
    public int solution(int coin, int[] cards) {

        int n = cards.length;

        HashSet<Integer> inMyHands = new HashSet<>();
        HashSet<Integer> additional = new HashSet<>();

        for (int i = 0; i < n / 3; i++) {
            inMyHands.add(cards[i]);
        }
        int answer = 0;

        int cardsPointer = inMyHands.size();

        int leftCoins = coin;

        // 나중에 업데이트하기
        while (true) {
            answer++;
            if (cardsPointer >= n) {
                break;
            }
            additional.add(cards[cardsPointer++]);
            additional.add(cards[cardsPointer++]);

            boolean flag = false;

            // 손에있는걸로 N+1을 만드는 경우
            for (int i : inMyHands) {
                if (inMyHands.contains(n + 1 - i)) {
                    inMyHands.remove(i);
                    inMyHands.remove(n + 1 - i);
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                // 코인을 한개만 써서 n+1을 만드는 경우
                for (int i : additional) {
                    if (leftCoins < 1) {
                        break;
                    }
                    if (inMyHands.contains(n + 1 - i)) {
                        inMyHands.remove(n + 1 - i);
                        additional.remove(i);
                        leftCoins--;
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag) {
                for (int i : additional) {
                    if (leftCoins < 2) {
                        break;
                    }
                    if (additional.contains(n + 1 - i)) {
                        additional.remove(n + 1 - i);
                        additional.remove(i);
                        leftCoins -= 2;
                        flag = true;
                        break;
                    }
                }
            }

            if (!flag) {
                break;
            }
        }

        return answer;
    }
}