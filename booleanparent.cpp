
int m[3][101][101];

int solve(string &s,int i,int j,bool isTrue)
{
    if(i>j)return false;
    if(i==j)
    {
        if(isTrue)return s[i]=='T';
        else return s[i]=='F';
    }
    if(m[isTrue][i][j]!=-1)return m[isTrue][i][j];
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=solve(s,i,k-1,1);
        int lf=solve(s,i,k-1,0);
        int rt=solve(s,k+1,j,1);
        int rf=solve(s,k+1,j,0);
        if(s[k]=='&')
        {
            if(isTrue)ans+=(lt*rt)%1003;
            else ans+=((lt*rf)%1003+(lf*rt)%1003+(lf*rf)%1003)%1003;
        }
        else if(s[k]=='|')
        {
            if(isTrue)ans+=((lt*rf)%1003+(lf*rt)%1003+(lt*rt)%1003)%1003;
            else ans+=(lf*rf)%1003;
        }
        else if(s[k]=='^')
        {
            if(isTrue)ans+=((lt*rf)%1003+(lf*rt)%1003)%1003;
            else ans+=((lf*rf)%1003+(lt*rt)%1003)%1003;
        }
    }
    return m[isTrue][i][j]=ans%1003;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    memset(m,-1,sizeof(m));
	    string s;
	    cin>>n>>s;
	    cout<<solve(s,0,n-1,true)<<"\n";
	}
	return 0;
}