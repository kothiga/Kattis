#include <iostream>

using namespace std;

int main() {

   int d1_a, d1_b, d2_a, d2_b, e, g;
   cin >> d1_a >> d1_b >> d2_a >> d2_b;

   g = d1_a + d1_b + d2_a + d2_b;
   
   cin >> d1_a >> d1_b >> d2_a >> d2_b;
   e = d1_a + d1_b + d2_a + d2_b;

   if (e == g) {
      cout << "Tie\n";
   } else if (e > g) {
      cout << "Emma\n";
   } else {
      cout << "Gunnar\n";
   }

   return 0;
}
