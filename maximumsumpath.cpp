#define ll long long
#define ull unsigned long long
using namespace std;

int min_path(vector<vector<int>>&a,int n,int m,int &limit,unordered_map<string,int>&map)
{
    if(limit==0)return 0;
    if(m==limit || m<0)return INT_MIN;
    if(n==limit-1)return a[n][m];
    string s=to_string(n)+" "+to_string(m); 
    if(map.find(s)!=map.end())return map[s];
    int r_path=min_path(a,n+1,m,limit,map);
    int c_path=min_path(a,n+1,m+1,limit,map);
    int d_path=min_path(a,n+1,m-1,limit,map);
    int path=max(r_path,c_path);
    path=max(path,d_path);
    return map[s]=a[n][m]+path;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    //int a[n][n];
	    vector<vector<int>>a(n,vector<int>(n));
	    int min_path_value=INT_MIN;
	    for(int i=0;i<n;++i)
	    {
	        for(int j=0;j<n;++j)
	        {
	            cin>>a[i][j];
	        }
	    }
	    unordered_map<string,int>map;
	    for(int i=0;i<n;++i)
	    {
	        min_path_value=max(min_path_value,min_path(a,0,i,n,map));
	        if(min_path_value==0)break;
	    }
	    min_path_value=min_path_value==INT_MIN ? 0:min_path_value;
	    cout<<min_path_value<<"\n";
	}
	return 0;
}