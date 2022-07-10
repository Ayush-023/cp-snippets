vector<long long> factor(long long n) 
{
    vector<long long> f;
    for(long long i=2;i*i<=n;i++)
    {
       	while(n%i==0) 
	    {
	        f.push_back(i);
	        n /= i;
	    }
    }

    if(n > 1)
       f.push_back(n);
   
    return f;
}