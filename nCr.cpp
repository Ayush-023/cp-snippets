long long nCr(long long n, long long r)
{
	long long ans = 1;

	if (r>n-r)
	r=n-r;

	for(long long i=0;i<r;i++)
	{
    	ans*= (n-i);
    	ans/= (i+1);
	}

	return ans;
}