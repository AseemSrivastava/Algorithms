using namespace std;

int ks(int a[],int n,int sum)
{
    int b[n+1][sum+1];
    for(int i=0;i<sum+1;++i)b[0][i]=INT_MAX-1;
    for(int i=1;i<n+1;++i)b[i][0]=0;
    for(int i=1;i<sum+1;++i)if(i%a[0]==0)b[1][i]=i/a[0];else b[1][i]=INT_MAX-1;
    for(int i=2;i<n+1;++i)
    {
        for(int j=1;j<sum+1;++j)
        {
            if(a[i-1]>j)b[i][j]=b[i-1][j];
            else b[i][j]=min(b[i][j-a[i-1]]+1,b[i-1][j]);
        }
    }
    return b[n][sum]>sum ? -1:b[n][sum];
}

int main() {
	int t,sum,n;
	cin>>t;
	while(t--)
	{
	    cin>>sum>>n;
	    int a[n];
	    for(int i=0;i<n;++i)cin>>a[i];
	    cout<<ks(a,n,sum)<<"\n";
	}
	return 0;
}