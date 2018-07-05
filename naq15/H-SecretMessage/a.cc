#include <iostream>
#include <string>

using namespace std;

int main() {

   int n;
   cin >> n;

   while (n--) {

      const int MAX = 105;
      char crypt[MAX][MAX];

      for (int i = 0; i < MAX; i++) {
	 for (int j = 0; j < MAX; j++) {
	    crypt[i][j] = '*';
	 }
      }
            
      string s;
      cin >> s;

      int l = s.length();

      int m;
      for (int i = 1; i <= 100; i++) {
	 if (i*i >= l) {
	    m = i;
	    break;
	 }
      }

      int cur = 0;
      for (int i = 0; i < m; i++) {
	 for (int j = 0; j < m; j++) {
	    if (cur < l) {
	       crypt[i][j] = s[cur];
	       cur++;
	    }
	 }
      }

      string output = "";
      for (int i = 0; i < m; i++) {
	 for (int j = m; j >= 0; j--) {
	    if (crypt[j][i] != '*') {
	       output += crypt[j][i];
	    }
	 }
      }

      cout << output << endl;
   }

   return 0;
}
