//Convex Hull Trick add elements and query in incresing order in O(n).
//dp[i] = max(B[j]+X[i]*A[j]);
//Tested on https://dmoj.ca/problem/apio10p1

deque<pair<int,int>> dq;
int interx(int a1, int b1, int a2, int b2) {
    return (b2-b1)/(a1-a2);
}
int func(int a, int b, int x) {
    return a*x + b;
}
void chtadd(int a, int b) {
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
