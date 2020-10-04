using namespace std;


int sub(vector<int>&v)
{
    int sum=0,n=v.size();
    for(int i:v)sum+=i;
    bool b[n+1][sum+1];
    for(int i=0;i<n+1;++i)b[i][0]=true;
    for(int i=1;i<sum+1;++i)b[0][i]=false;
    for(int i=1;i<n+1;++i)
    {
        for(int j=1;j<sum+1;++j)
        {
            if(j<v[i-1])b[i][j]=b[i-1][j];
            else b[i][j]=b[i-1][j-v[i-1]] || b[i-1][j];
        }
    }
    int minn=INT_MAX;
    for(int i=1;i<=sum/2;++i)if(b[n][i])minn=min(minn,sum-2*i);
    return minn==INT_MAX ? 0 : minn;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;++i)cin>>v[i];
        cout<<sub(v)<<"\n";
    }
    
    return 0;
}