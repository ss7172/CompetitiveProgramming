#include "bits/stdc++.h"
using namespace std;

// Pragmas
#pragma GCC optimize("O3,unroll-loops")


// Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;


// Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-16;
constexpr ll MOD = 1e9 + 7;;

// Macros
#define F first
#define S second
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
// Custom hash map
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream& istream, pair<T1, T2>& p)
{
    return (istream >> p.first >> p.second);
}

template <typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v)
{
    for (auto& it : v)
        cin >> it;
    return istream;
}

template <typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream& ostream, const pair<T1, T2>& p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream& operator<<(ostream& ostream, const vector<T>& c)
{
    for (auto& it : c)
        cout << it << " ";
    return ostream;
}

// Utility functions
template <typename T>
void print(T&& t) { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T&& t, Args &&...args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
int32_t size_i(T& container) { return static_cast<int32_t>(container.size()); }

// Mathematical functions
int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int GCD_extended(int a, int b, int& x, int& y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int LCM(int a, int b)
{
    return ((ll)a * b) / GCD(a, b);
}

ll modpow(ll x, ll n, int m = MOD)
{
    if (x == 0 && n == 0)
        return 0; // undefined case
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

int modinv(int x, int m = MOD)
{
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}
 ///////////////////////////////////////////////////////////// START CODE HERE /////////////////////////////////////////////////////////////

void preSolve()
{
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

}

vector<pair<int,int>> get_expansions(int v) {
    vector<pair<int,int>> result;
    if (v < 10) {
        result.push_back({v, v});
    } else {
        result.push_back({v, v});
        int X = v / 10, Y = v % 10;
        if (X <= Y) {
            result.push_back({X, Y});
        }
    }
    cout << "result = " <<  result << endl;
    
    return result;
}
#include <typeinfo>

void solve(int tc)
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    cin >> arr;
    vector<unordered_set<int>> dp(n+1);
    

    for (auto &exp0 : get_expansions(arr[0])) {
        // cout << "exp0 = " << exp0 << endl;
        dp[1].insert(exp0.second);
    }

    for(int i=1; i<n; i++){
        for (int lastVal : dp[i]) {
            for (auto &expNext : get_expansions(arr[i])) {
                // cout << "expNext = " << expNext << endl;
                int f = expNext.first;
                int l = expNext.second;
                if (lastVal <= f) {
                    dp[i+1].insert(l);
                }
            }
        }
    }

    if (!dp[n].empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    // ll i = n - 1;
    // while (i > 0) {
    //     ll x = array[i];
    //     ll y = array[i - 1];
    //     ll x1 = x%10;
    //     x = x/10;
    //     ll x2 = x%10;
    //     ll y1 = y%10;
    //     y = y/10;
    //     ll y2 = y%10;
    //     if (x2 == 0) {
    //         if (!(y2 <= y1 && y1 <= x1)) {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    //     else if (x2 != 0) {
    //         if (!(y2 <= y1 && y1 <= x2 && x2 <= x1)) {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
    //     else if (x2 == 0 && y2 == 0) {
    //         if (!(y1 <= x1)) {
    //             cout << "NO\n";
    //             return;
    //         }
    //     }
        // if (x2 > x1 || y2 > y1) {
        //     cout << "NO\n";
        //     return;
        // }
        // if (x2 == 0 && y2 > x1 || y1 > x1) {
        //     cout << "NO\n";
        //     return;
        // }
        // if (y2 > x2 || y1 > x2) {
        //     cout << "NO\n";
        //     return;
        // }
        // i--;
    // }
    // cout << "YES\n";
   
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;

    preSolve();
    int tests = 1;
    cin >> tests;
    for (int tt = 1; tt <= tests; tt++)
        solve(tt);
    return 0;
}
