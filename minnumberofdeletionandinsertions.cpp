using namespace std;

int lcs(string a,string b,int n,int m)
{
    int t[n+1][m+1];
    for(int i=0;i<n+1;++i)t[i][0]=0;
    for(int i=0;i<m+1;++i)t[0][i]=0;
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<m+1;++j)
        {
            if(a[i-1]==b[j-1])t[i][j]=1+t[i-1][j-1];
            else t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    return t[n][m];
}

int main() {
    int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    string a,b;
	    cin>>n>>m>>a>>b;
	    cout<<n+m-2*lcs(a,b,n,m)<<"\n";
	}
	return 0;
}