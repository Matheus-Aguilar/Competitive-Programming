#include <bits/stdc++.h>
 
using namespace std;
 
long double calcArea(vector<pair<long double, long double>> &p)
{
   long double res = 0;
   for (int i = 1; i < p.size(); i++)
   {
       res += (p[i].first * p[i - 1].second) - (p[i - 1].first * p[i].second);
   }
 
   res += (p[0].first * p[p.size() - 1].second) - (p[p.size() - 1].first * p[0].second);
 
   return res / 2;
}
 
int main()
{
   int n;
   while (cin >> n)
   {
       long double angulo = (2 * 3.141592653589793) / n;
       vector<int>v(n);
       vector<int>v2(n);
       vector<pair<long double, long double>> p(n);
       for (int i = 0; i < n; i++)
       {
           cin >> v[i];
       }

       sort(v.begin(), v.end());
       for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                v2[i/2] = v[i];
            else
                v2[v.size() - i/2 - 1] = v[i];
       }

       for (int i = 0; i < n; i++)
       {
           p[i] = make_pair(v2[i] * cos(i * angulo), v2[i] * sin(i * angulo));
       }

       cout << fixed << setprecision(3) << fabsl(calcArea(p)) << endl;
   }
}

