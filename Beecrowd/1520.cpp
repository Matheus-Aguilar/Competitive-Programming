#include<bits/stdc++.h>

using namespace std;

// Returns sum of arr[0..index]. This function assumes 
// that the array is preprocessed and partial sums of 
// array elements are stored in BITree[] 
int getSum(int BITree[], int index){
	int sum = 0; // Initialize result 

	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse ancestors of BITree[index] 
	while (index>0) 
	{ 
		// Add current element of BITree to sum 
		sum += BITree[index]; 

		// Move index to parent node in getSum View 
		index -= index & (-index); 
	} 
	return sum; 
} 

// Updates a node in Binary Index Tree (BITree) at given 
// index in BITree. The given value 'val' is added to 
// BITree[i] and all of its ancestors in tree. 
void updateBIT(int BITree[], int n, int index, int val){ 
	// index in BITree[] is 1 more than the index in arr[] 
	index = index + 1; 

	// Traverse all ancestors and add 'val' 
	while (index <= n) 
	{ 
		// Add 'val' to current node of BI Tree 
		BITree[index] += val; 

		// Update index to that of parent in update View 
		index += index & (-index); 
	} 
} 

// Returns the sum of array from [0, x] 
int sum(int x, int BITTree1[], int BITTree2[]){ 
	return (getSum(BITTree1, x) * x) - getSum(BITTree2, x); 
} 


void updateRange(int BITTree1[], int BITTree2[], int n, 
				int val, int l, int r){ 
	// Update Both the Binary Index Trees 
	// As discussed in the article 

	// Update BIT1 
	updateBIT(BITTree1,n,l,val); 
	updateBIT(BITTree1,n,r+1,-val); 

	// Update BIT2 
	updateBIT(BITTree2,n,l,val*(l-1)); 
	updateBIT(BITTree2,n,r+1,-val*r); 
} 

int rangeSum(int l, int r, int BITTree1[], int BITTree2[]){ 
	// Find sum from [0,r] then subtract sum 
	// from [0,l-1] in order to find sum from 
	// [l,r] 
	return sum(r, BITTree1, BITTree2) - 
		sum(l-1, BITTree1, BITTree2); 
} 


int *constructBITree(int n){ 
	// Create and initialize BITree[] as 0 
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 

	return BITree; 
} 

// Driver Program to test above function 
int main(){ 
	int n;
    while(scanf("%d", &n) == 1){
        vector<pair<int, int>> boxes(n);

        int biggest = 0;

        while(n--){
            int a, b;
            scanf("%d%d", &a, &b);
            boxes[n] = make_pair(a, b);
            biggest = max(biggest, b);
        }
        
        // Construct two BIT 
        int *BITTree1, *BITTree2; 

        // BIT1 to get element at any index 
        // in the array 
        BITTree1 = constructBITree(biggest); 

        // BIT 2 maintains the extra term 
        // which needs to be subtracted 
        BITTree2 = constructBITree(biggest);
        
        for(int i = 0; i < boxes.size(); i++)
			updateRange(BITTree1, BITTree2, biggest, 1, boxes[i].first - 1, boxes[i].second - 1);
		int x;
		scanf("%d", &x);
		if(x <= biggest && rangeSum(x - 1, x - 1, BITTree1, BITTree2))
			printf("%d found from %d to %d\n", x, rangeSum(0, x - 2, BITTree1, BITTree2), rangeSum(0, x - 1, BITTree1, BITTree2) - 1);
		else
			printf("%d not found\n", x);
    }
	return 0; 
} 
