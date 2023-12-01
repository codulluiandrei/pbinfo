int mp(int x)
{
	if(x >= 12)
		return x - 1;
	else
		return mp( mp(x + 2) );
}