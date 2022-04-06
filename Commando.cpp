#include<bits/stdc++.h>
using namespace std;

const long long inf = (long long) 1e18 + 10;
const int inf1 = (int) 1e9 + 10;
#define int long long
#define dbl long double
#define endl '\n'
#define sc second
#define fr first
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()

const int maxn = 1e6+10;

int n, ps[maxn], dp[maxn];
deque<pair<int,int>> dq;

int interx(int a1, int b1, int a2, int b2) {
    return (b2-b1)/(a1-a2);
}

int func(int a, int b, int x) {
    return a*x + b;
}

void chtadd(int a, int b) {
    //tiro o cara igual se tiver
    if(dq.size() && dq.back().fr == a) {
        if(b <= dq.back().sc) return;
        dq.pop_back();
    }

    while(dq.size() >= 2) {
        if(interx(a,b,dq.back().fr,dq.back().sc) <= interx(dq.back().fr,dq.back().sc,dq[dq.size()-2].fr,dq[dq.size()-2].sc)) {
            dq.pop_back();
        }
        else
            break;
    }
    dq.push_back(mp(a,b));
}

int chtqrr(int x) {
    while(dq.size() >= 2) {
        if(func(dq[1].fr,dq[1].sc,x) >= func(dq[0].fr,dq[0].sc,x)) dq.pop_front();
        else break;
    }
    return func(dq[0].fr,dq[0].sc,x);
}

void solve() {
    cin >> n;
    int A,B,C;
    cin >> A >> B >> C;

    for(int i = 1; i <= n; i++) {
        cin >> ps[i];
        ps[i]+= ps[i-1];
    }

    chtadd(0,0);
    for(int i = 1; i <= n; i++) {
        auto qr = chtqrr(-2*A*ps[i]);
        dp[i] = A*ps[i]*ps[i] + B*ps[i] + C + qr;
        chtadd(ps[i],A*ps[i]*ps[i]-B*ps[i]+dp[i]);
    }
    cout << dp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);

    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }

}