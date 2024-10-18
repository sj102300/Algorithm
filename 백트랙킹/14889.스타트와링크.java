//[실버1] 14889.스타트와링크 https://www.acmicpc.net/problem/14889

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;
    static int[][] S;
    static int minDiff;
    static ArrayList<Integer> ATeam;
    static ArrayList<Integer> BTeam;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ATeam = new ArrayList<>();
        BTeam = new ArrayList<>();

        n = Integer.parseInt(br.readLine());

        S = new int[n][n];
        minDiff = 123456789;

        for (int i = 0; i < n; i++) {
            String[] line = br.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                S[i][j] = Integer.parseInt(line[j]);
            }
        }

        btrk(0, ATeam, BTeam);

        System.out.println(minDiff);

        br.close(); // BufferedReader 닫기
    }

    private static void btrk(int m, ArrayList<Integer> ATeam, ArrayList<Integer> BTeam) {

        if(m == n){
            //종료조건
            if(ATeam.size() == BTeam.size() && ATeam.size() == n/2){
                //정답인지 확인, 여기서 mindiff계산
                int sumA = 0;
                int sumB = 0;
                for(int i=0;i<n/2;i++){
                    for(int j=0;j<n/2;j++){
                        int a = ATeam.get(i);
                        int b = ATeam.get(j);
                        sumA += S[a][b];
                    }
                }
                for(int i=0;i<n/2;i++){
                    for(int j=0;j<n/2;j++){
                        int a = BTeam.get(i);
                        int b = BTeam.get(j);
                        sumB += S[a][b];
                    }
                }
                minDiff = Math.min(Math.abs(sumA - sumB), minDiff);
            }
            return;
        }

        ATeam.add(m);
        btrk(m+1, ATeam, BTeam);
        ATeam.remove(ATeam.size()-1);
        BTeam.add(m);
        btrk(m+1, ATeam, BTeam);
        BTeam.remove(BTeam.size()-1);

    }

}
