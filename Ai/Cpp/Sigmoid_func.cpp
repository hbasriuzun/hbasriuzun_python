#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll sigmoid(ll x){
    return 1 / (1 + exp(-x));
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cout << exp(v[i]) << " ";
    }
    
    cout << "\n";

    for (ll i = 0; i < n; i++)
    {
        cout << sigmoid(v[i]) << " ";
    }
    return 0;
}