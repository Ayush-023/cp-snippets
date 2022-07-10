long long modInverse(long long a, long long m)
{
	long long o = m;
	long long y = 0, x = 1;

	if(m==1)
		return 0;

	while(a>1)
	{
		long long q = a/m;
		long long u = m;
		m = a%m, a = u;
		u = y;
		y = x-q*y;
		x = u;
	}

	if(x<0)
		x += o;

	return x;
}