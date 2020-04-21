
#include <iostream>
//#define cin ios::sync_with_stdio(false); cin
using namespace std;
typedef unsigned long long ll;

ll qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int main(){
      ll m, k, p;
      m = 2;
      p = 100000;

      while (cin >> k) {
            ll ans = qmi(m, k, p);
            cout << ans << '\n';
      }

      return 0;
}