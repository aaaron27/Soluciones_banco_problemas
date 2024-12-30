#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAX_EDAD = 120;

int main(){
   int D, R, T;
   cin >> D >> R >> T;

   // suma de las velas que deberian tener a su respectiva edad
   vi theo(MAX_EDAD, 0);
   vi rita(MAX_EDAD, 0);

   // generamos todas las sumas hasta i = 70
   for (int i = 3; i < MAX_EDAD; i++){
       if (i >= 3) theo[i] = i + theo[i-1];
       if (i >= 4) rita[i] = i + rita[i-1];
   }

   // i: edad de Rita
   // i - D: edad de Theo
   for (int i = D; i < MAX_EDAD; i++){
       // la cantidad de velas de theo y rita
       // deben ser iguales a la cantidad total de velas entre las dos cajas
       if (theo[i-D] + rita[i] == R+T) { cout << R - rita[i] << '\n'; break; }
   }

   return 0;
}
