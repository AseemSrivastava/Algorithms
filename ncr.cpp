using namespace std;
#define MOD 1000000007
int nCrModp(int n,int r)
{
    int C[r+1]={0};
    C[0]=1;
    for (int i=1;i<=n;++i)
    {
        for(int j=min(i,r);j>0;--j)C[j]=(C[j]+C[j-1])%MOD;
    }
    return C[r];
}
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n,r;
         cin>>n>>r;
         cout<<nCrModp(n,r)<<" \n";
     }
    return 0;
}