#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void prepare_pattern (const vector<int> &pat, vector<int> &T) {
  int n = pat.size();
  T.resize(n+1);
  fill(T.begin(), T.end(), -1);
  for (int i = 1; i <= n; i++) {
    int pos = T[i-1];
    while (pos != -1 && pat[pos] != pat[i-1]) {
      pos = T[pos];
    }
    T[i] = pos + 1;
  }
}

int find_pattern (const vector<int> &s,
		  const vector<int> &pat,
		  const vector<int> &T) {
   
  int sp = 0, kp = 0;
  int slen = s.size(), plen = pat.size();
  while (sp < slen) {
    while (kp != -1 && (kp == plen || pat[kp] != s[sp])) {
      kp = T[kp];
    }
    
    kp++;   sp++;
    if (kp == plen) {
      // a match is found
      return sp - plen;

      // if you want more than one match (i.e. all matches), do not return
      // in the above but rather record the location of the match.  Continue
      // the loop with:
      //
      // kp = T[kp];
    }
  }
  return -1;
}




int main() {

   int N, M, MAX=360000;
   cin >> N;

   M = N*2;
   vector<int> a(N);
   vector<int> b(M);

   for (int i = 0; i < N; i++) {
      cin >> a[i];
   }
  

   for (int i = 0; i < N; i++) {
      cin >> b[i*2];
      b[i*2 + 1] = b[i*2] + MAX;
   }
   

   sort(a.begin(), a.end());
   a.push_back(a[0]+MAX);
   
   sort(b.begin(), b.end());

   vector<int> a_gap;
   vector<int> b_gap;
   
   int len = a.size()-1;
   for (int i = 0; i < len; i++) {
      a_gap.push_back(a[i+1] - a[i]);
   }
   
   len = b.size()-1;
   for (int i = 0; i < len; i++) {
      b_gap.push_back(b[i+1] - b[i]);
   }

   //kmp
   vector<int> T;
   prepare_pattern(a_gap, T);
   
   if (find_pattern(b_gap, a_gap, T) == -1) {
      cout << "impossible\n";
   } else {
      cout << "possible\n";
   }
   
   return 0;
}
