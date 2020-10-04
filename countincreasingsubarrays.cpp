using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;++i)
	    {
	        cin>>a[i];
	    }
	    int counter=0,count=1;
	    for(int i=1;i<n;++i)
	    {
	        if(a[i]>a[i-1])++count;
	        else {
	            counter+=((count*(count-1))/2);
	            count=1;
	        }
	    }
	    if(count>1)
	    counter+=((count*(count-1))/2);
	    cout<<counter<<"\n";
	}
	return 0;
}
