#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

long long int tree[MAX * 4];
long long int lazy[MAX * 4];

void build(long long int node, long long int start, long long int end){
    if(start == end){
        // Leaf node will have a single element
        tree[node] = 0;
        lazy[node] = 0;
    }
    else{
        long long int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // long long internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
        lazy[node] = 0;
    }
}

void updateRange(long long int node, long long int start, long long int end, long long int l, long long int r, long long int val){
    if(lazy[node] != 0){ 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r){
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end){
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    long long int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

long long int queryRange(long long int node, long long int start, long long int end, long long int l, long long int r){
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end){
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    long long int mid = (start + end) / 2;
    long long int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    long long int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

int main(){
    long long int n, t;
    scanf("%Ld", &t);
    while(t--){
        long long int c;
        scanf("%Ld%Ld", &n, &c);
        build(1, 0, n - 1);
        while(c--){
            long long int l, r, op;
            long long int v;
            scanf("%Ld", &op);
            if(op){
                //cin >> l >> r;
                scanf("%Ld%Ld", &l, &r);
                printf("%Ld\n", queryRange(1, 0, n - 1, min(l, r) - 1, max(l, r) - 1));
            }
            else{
                //cin >> l >> r >> v;
                scanf("%Ld%Ld%Ld", &l, &r, &v);
                updateRange(1, 0, n - 1, min(l, r) - 1, max(l, r) - 1, v);
            }
        }
    }
}

