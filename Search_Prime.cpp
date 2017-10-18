#include<iostream>
#include<math.h>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

const int times=20;
int number=0;
map<long long,int>m;

long long Random(long long n)
{
	return((double)rand()/RAND_MAX*n+0.5);
}

long long q_mul(long long a,long long b,long long mod)//快速计算(a*b)%mod
{
	long long ans=0;
	while(b)
	{
		if(b&1)
		{
		  b--;
		  ans=(ans+a)%mod;
		}
		b/=2;
		a=(a+a)%mod;
	}
	return ans;
}

long long q_pow(long long a,long long b,long long mod)//快速计算(a^b)%mod
{
	long long ans =1;
	while(b)
	{
		if(b&1)
		{
			ans=q_mul(ans ,a,mod);
		}
		b>>=1;
		a=q_mul(a,a,mod);
	}
	return ans;
}

bool witness(long long a,long long n)
{
	long long tem=n-1;
	int j=0;
	while((tem&1)==0)
	{
		tem>>=1;
		j++;
	}
	long long x=q_pow(a,tem,n);
	if(x==1||x==n-1)
		return true;
	while(j--)
	{
		x=qul(x,x,n)
			if(x==n-1)
				return true;
	}
	return false;
}

bool miller_rabin(long long n)
{
	if(n==2)
		return true;
	if(n<2||n%2==0)
		return false;
	for(int i=1;i<=times;i++)
	{
		long long a=Random(n-2)+1;
		if(!witness(a,n))
			return false;
	}
	return true;
}

int main(){
	long long tar;
	while(cin>>tar)
	{
		if(miller_rabin(tar))
			cout<<"是素数"<<endl;
		else
			cout<<"不是素数"<<endl;
	}
	return 0;
}

