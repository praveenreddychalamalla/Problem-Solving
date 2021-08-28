/**
 * @author Praveen Reddy Chalamalla
 * @create date 2021-08-27
 * @desc Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
 *       return the maximum number of points that lie on the same straight line.
 */


//Time Complexity - O(n*n), Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

/**
 * Note: Representing slope in double or float can yeild preicision errors. Hence use co-prime representation for slope.
*/
int maxPoints(vector<vector<int>>& a) {
    unordered_map<double,int>m;
    int n=a.size(),res=1; //points=[0,0], ans=1
    for(int i=0;i<n;i++){
        double x1=a[i][0],y1=a[i][1]; //Fix the point p1 and Check how many points are collinear with this
        for(int j=0;j<n;j++){
            if(i!=j){
                double x2=a[j][0],y2=a[j][1];
                if(x2==x1){ //Slope is undefined
                    m[INT_MAX]++;
                    res=max(res,m[INT_MAX]+1);//Update the res
                }
                else{
                    double slope=(y2-y1)/(x2-x1); //Calculate slope with p1
                    m[slope]++;
                    res=max(res,m[slope]+1); //Update the res
                }
            }   
        } 
        m.clear();//Erase the map
    }
    
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< vector<int> > points(n,vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin>>points[i][j];
            }
        }
        auto ans =maxPoints(points);
        cout << ans << "\n";
    }
    return 0;
}
