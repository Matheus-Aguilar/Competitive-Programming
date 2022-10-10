#include <bits/stdc++.h>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long ll;
const int mx = 2e4 + 10;
int n,P;
int b[mx];
int x1,x2,o1,y2;
struct node {
	int x1,o1;
	int x2,y2;
}s[mx];
 
struct seg {
	int l,r;
	int h,d;
	bool operator < (seg A) const {
		return h < A.h;
	}
}a[mx];
 
int cnt[mx<<2],sum[mx<<2];
 
void push_up(int l, int r, int rt) {
    if(cnt[rt]) sum[rt] = b[r + 1] - b[l];
    else if(l == r) sum[rt] = 0; //leaves have no sons
    else sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
 
void update(int l, int r, int rt, int L, int R, int v) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int mid = l + r >> 1;
    if(L <= mid) update(lson, L, R, v);
    if(R > mid) update(rson, L, R, v);
    push_up(l, r, rt);
}
 
bool check(int mid) {
	static ll area = 1ll*(x2-x1)*(y2-o1);
	int siz = 0, is = 0;
	int X1,X2,Y1,Y2;
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for (int i=1;i<=n;i++) {
		X1 = s[i].x1 - mid;
		X2 = s[i].x2 + mid;
		Y1 = s[i].o1 - mid;
		Y2 = s[i].y2 + mid;
		int lx = max(X1,x1);
		int rx = min(X2,x2);
		int ly = max(Y1,o1);
		int ry = min(Y2,y2);
		if (lx > rx || ly > ry) continue;
		b[++siz] = lx;
		a[siz] = {lx,rx,ly,1};
		b[++siz] = rx;
		a[siz] = {lx,rx,ry,-1};
	}
	sort(b+1,b+siz+1);sort(a+1,a+siz+1);
	is = unique(b+1,b+siz+1) - b;
	ll ans = 0;

	for (int i=1;i<=siz;i++) {
		int L = lower_bound(b+1,b+is,a[i].l) - b;
		int R = lower_bound(b+1,b+is,a[i].r) - b - 1;

        cout << L << " " << R << "\n";

        update(1,is-1,1,L,R,a[i].d);//扫描线段时更新底边长度和底边相差个数
        ans += 1ll*sum[1]*(a[i+1].h-a[i].h);//新增加面积
    }

    cout << ans << " " << mid << " " << area << "\n";

	return ans * 100 / area >= P;
} 
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d%d%d",&s[i].x1,&s[i].o1,&s[i].x2,&s[i].y2); 
	}
	scanf("%d",&P);
	scanf("%d%d%d%d",&x1,&o1,&x2,&y2);
	
    
    check(62500); return 0;
    
    int l = 1,r = 1e6;
	while (l < r) {
		int mid = l+r>>1;
		if (check(mid))
			r = mid;
		else 
			l = mid + 1;
	}
	printf("%d\n",l);
	return 0;
}