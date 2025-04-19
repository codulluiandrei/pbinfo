void nule(std::vector<int> &v)
{
    int i, k = 0, size = v.size();
    for(i = 0; i < size; i++)
        if(v[i] != 0)
            v[k++] = v[i];
    for(i = k; i < size; i++)
        v[i] = 0;
}