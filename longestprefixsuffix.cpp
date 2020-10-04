#define ll long long
#define ull unsigned long long
using namespace std;


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string tmp,s;
	    cin>>tmp;
	    s.push_back('0');
	    for(int i=0;i<tmp.size();++i)s.push_back(tmp[i]);
	    vector<int>lps(s.size(),0);
	    int i=0,j=2;
	    while(j<s.size())
	    {
	        if(s[i+1]==s[j])
	        {
	            ++i;
	            lps[j++]=i;
	        }
	        else if(i!=0)i=lps[i];
	        else lps[j++]=i;
	    }
	    cout<<lps[lps.size()-1]<<"\n";
	}
	return 0;
}