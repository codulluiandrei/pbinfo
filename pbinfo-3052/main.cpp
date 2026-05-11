#include <bits/stdc++.h>
#include <string>
using namespace std;
ifstream in("nozero.in");
ofstream out("nozero.out");
long long n,k,ans,b,c,nr[ 100 ], fact[ 100 ], v[ 100 ],p[ 100 ], a;
int z;
int hasZero( int x )
{
	while( x )
	{
		if( x % 10 == 0 )
			return 1;
		x /= 10;
	}
	return 0;
}
int main()
{
	nr[ 0 ] = 1;
	nr[ 1 ] = 9;
	fact[ 0 ] = fact[ 1 ] = p[ 0 ] = 1;
	p[ 1 ] = 2;
	for( int i = 2 ; i <= 15 ; i++ )
	{
		nr[ i ] = nr[ i - 1 ] * 9;
		fact[ i ] = fact[ i - 1 ] * i;
		p[ i ] = i + 1;
	}
	in >> n >> k;
	a = n;
	n = max( 0ll , n - 15 );
	b = n;
	z = n;
	string st;
	while(z)
    {
        st.push_back( z % 10 + '0' );
        z /= 10;
    }
    reverse(st.begin() , st.end());
	for( int i = 1 ; i < st.size() ; i++ )
	{
		ans += nr[ i ];
	}
	int zero = 1;
	if( st.size() == 0 )
        zero = 0;
	for( int i = 0 ; i < st.size() ; i++ )
	{
		int c = st[ i ] - '0';
		if( c == 0 )
		{
			zero = 0;
			break;
		}
		ans += (c - 1) * nr[ st.size() - i - 1 ];
	}
	ans += zero;
	a = min( 15ll , a );
	k--;
	for( int i = 1 ; i <= a ; i++ )
	{
		c = ( k / fact[ a - i ] );
		v[ i ] = p[ c ];
		for( int j = c ; j <= a ; j++ )
		{
			p[ j ] = p[ j + 1 ];
		}
		k -= c * fact[ a - i ];
		if( !hasZero( v[ i ] + n ) && !hasZero( i + n ) )
			ans++;
	}
	out << ans;
	return 0;
} 