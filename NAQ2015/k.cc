/*
  Solution for NAQ2015 problem k
  https://open.kattis.com/contests/onyyqy/problems/undetected

     Compile : g++11 -std=c++11 -o k k.cc -Wall
  Written by : Austin Kothig
    Semester : FALL 2017
     Problem : given a set of sensors, what are the max
               number of sensors that can be placed
               before the robot would be detected
*/

#include <iostream>

using namespace std;

class UnionFind
{
      struct UF { int p; int rank; };

   public:
      UnionFind(int n) {          // constructor
	 howMany = n;
	 uf = new UF[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
	 }
      }

      ~UnionFind() {
         delete[] uf;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
	    }
	    else {
	       uf[res1].p = res2;
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
   private:
      int howMany;
      UF* uf;

      int find(UF uf[], int x) {     // recursive funcion for internal use
	 if (uf[x].p != x) {
	    uf[x].p = find(uf, uf[x].p);
	 }
	 return uf[x].p;
      }
};


const int MAX_N = 201;
const int L = 201;
const int R = 202;
int s[MAX_N][3];

int main() {
   int N, count = 0;
   cin >> N;

   for (int i = 0; i < MAX_N; i++)
      for (int j = 0; j < 3; j++)
	 s[i][j] = 0;

   UnionFind uf(MAX_N+2);
   
   for (int n = 0; n < N; n++) {
      // get    x          y          r
      cin >> s[n][0] >> s[n][1] >> s[n][2];

      // ask if point n intersects with left side
      if (s[n][0] < s[n][2]) {
	 uf.merge(n, L);
      }

      // ask if point n intersects with right side
      if (s[n][0]+s[n][2] > 200) {
	 uf.merge(n, R);
      }
	 
      // go through the previous points and ask if
      // they intersect with the current point
      for (int i = 0; i < n; i++) {

	 if ( (s[n][2]+s[i][2])*(s[n][2]+s[i][2]) >
	      ( (s[n][0]-s[i][0])*(s[n][0]-s[i][0]) ) +
	      ( (s[n][1]-s[i][1])*(s[n][1]-s[i][1]) ) ) {

	    uf.merge(i, n);
	 }

      }
      
      if (uf.find(R) == uf.find(L)) break;
      count++;
   }
   
   cout << count << endl;
}
