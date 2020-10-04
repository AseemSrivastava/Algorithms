using namespace std;
#define ull unsigned long long
ull ugly(ull n)
{
    ull uglya[n];
    uglya[0]=1;
    ull mul_2=2,mul_3=3,mul_5=5,ugly_num=1,i2,i3,i5;
    i2=i3=i5=0;
    for(ull i=1;i<n;++i)
    {
        mul_2=2*uglya[i2];
        mul_3=3*uglya[i3];;
        mul_5=5*uglya[i5];
        uglya[i]=min(mul_2,min(mul_3,mul_5));
        ugly_num=uglya[i];
        if(ugly_num==mul_2)
        {
            ++i2;
            mul_2=uglya[i]*2;
        }
        if(ugly_num==mul_3)
        {
            ++i3;
            mul_3=uglya[i]*3;
        }
        if(ugly_num==mul_5)
        {
            ++i5;
            mul_5=uglya[i]*5;
        }
    }
    return ugly_num;
}

int main() {
	ull n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<ugly(n)<<"\n";
	}
	return 0;
}