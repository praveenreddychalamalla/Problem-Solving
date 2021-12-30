 /**
  * @author Praveen Reddy Chalamalla
  * @create date 2021-11-16
  * @desc find Kth Smallest Number in an nxn matrix  where each of the rows and columns is sorted in ascending order
  */

//Time Complexity - O(n log(n)), Space Complexity - O(1)

int countSmaller(vector<vector<int>>& a, int n ,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(a[i].begin(),a[i].end(),x)-a[i].begin();
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int l=a[0][0],r=a[n-1][n-1];
        while(l<=r){
            int mid=(l+r)/2;
            if(countSmaller(a,n,mid)<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
	

int main() { 
	int t;
    cin>>t;
    while(t--){

 		int n;
    	cin>> n;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        cout<<KthSmallest(matrix,x);
    }
	return 0; 
} 