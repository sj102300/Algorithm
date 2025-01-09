//[실버1] 2531.회전초밥 https://www.acmicpc.net/problem/2531

#include <iostream>
using namespace std;
#include <vector>

int main(void) {
  int N, d, k, c;
  int answer = 0;
  int maxAnswer = 0;

  cin >> N >> d >> k >> c;

  vector<int> sushi(N, 0);

  for (int i = 0; i < N; ++i)
    cin >> sushi[i];

  vector<int> cnt(d + 1, 0);
  ++cnt[c];
  ++answer;

  for (int i = 0; i < k; ++i) {
    if (cnt[sushi[i]] == 0)
      ++answer;
    ++cnt[sushi[i]];
  }

  maxAnswer = max(answer, maxAnswer);

  for (int i = 1; i < N; ++i) {
    cnt[sushi[i - 1]]--;
    if (cnt[sushi[i - 1]] == 0)
      answer--;
    if (cnt[sushi[(i + k - 1) % N]] == 0)
      answer++;
    cnt[sushi[(i + k - 1) % N]]++;
    maxAnswer = max(answer, maxAnswer);
  }

  cout << maxAnswer;
}