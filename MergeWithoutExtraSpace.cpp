#define ll long long
#define ull unsigned long long
using namespace std;


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    int a[n],b[m];
	    vector<int>v;
	    for(int i=0;i<n;++i)cin>>a[i];
	    for(int i=0;i<m;++i)cin>>b[i];
	    int i=0,j=0;
	    while(i<n && j<m)
	    {
	        if(a[i]<b[j])
	        {
	            cout<<a[i]<<" ";++i;
	        }
	        else if(b[j]<a[i])
	        {
	            cout<<b[j]<<" ";++j;
	        }
	        else if(a[i]==b[j])
	        {
	            cout<<a[i]<<" "<<a[i]<<" ";++i;++j;
	        }
	    }
	    while(i<n)
	    {
	        cout<<a[i]<<" ";++i;
	    }
	    while(j<m)
	    {
	        cout<<b[j]<<" ";++j;
	    }
    	cout<<"\n";
	}
}