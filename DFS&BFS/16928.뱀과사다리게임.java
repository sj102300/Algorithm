//[골드5] 16928.뱀과사다리게임 https://www.acmicpc.net/problem/16928

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        HashMap<Integer, Integer> snakeAndLadder = new HashMap<>();

        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);

        for (int i = 0; i < N + M; i++) {
            line = br.readLine().split(" ");
            snakeAndLadder.put(Integer.valueOf(line[0]), Integer.valueOf(line[1]));
        }

        Integer[] visited = new Integer[101];
        Arrays.fill(visited, 123456789); // 배열의 모든 요소를 Infinity로 초기화

        Queue<Integer> queue = new LinkedList<>();

        visited[1] = 0;
        for (int i = 2; i <= 7; i++) {
            queue.add(i);
            visited[i] = 1;
        }

        while (!queue.isEmpty()) {
            Integer first = queue.poll();

            if (snakeAndLadder.containsKey(first)) {
                Integer value = snakeAndLadder.get(first);
                if (visited[value] > visited[first]) {
                    visited[value] = visited[first];
                    queue.add(value);
                }
            }
            else{
                for (int i = 1; i <= 6; i++) {
                    if (first + i <= 100) {
                        if (visited[first + i] > visited[first] + 1) {
                            visited[first + i] = visited[first] + 1;
                            queue.add(first + i);
                        }
                    }
                }
            }
        }

        // 출력하기
        System.out.println(visited[100]); // 결과 출력

        br.close(); // BufferedReader 닫기
    }
}
