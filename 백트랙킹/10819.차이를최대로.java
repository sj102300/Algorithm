//[실버2] 10819.차이를최대로 https://www.acmicpc.net/problem/10819

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
        static int n;
        static int[] array;
        static boolean[] visited;
        static int answer;
        public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        answer = 0;

        array = new int[n];

        String[] line = br.readLine().split(" ");
        for(int i=0;i<n;i++){
            array[i] = Integer.parseInt(line[i]);
        }

        visited = new boolean[n];

        int[] emptyArray = new int[n];

        btrk(0, emptyArray);

        System.out.println(answer+"");


        br.close(); // BufferedReader 닫기
    }

    private static void btrk(int m, int[] selected){

        if(m == n){
            //종료조건
            int sum = 0;
            for(int i=0; i<n-1;i++){
                sum += Math.abs(selected[i] - selected[i+1]);
            }
            answer = Math.max(answer, sum);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                int[] newArray = Arrays.copyOf(selected, selected.length);
                newArray[m] = array[i];
                btrk(m+1, newArray);
                visited[i] = false;
            }
        }
    }
}
