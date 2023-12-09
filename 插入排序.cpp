void InsertSort(int*a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int end=i,ret=a[end+1];
        while(end>=0)
        {
            if(a[end]>ret)
            {
                a[end+1]=a[end];
                end--;
            }
            else
                break;
        }
        a[end+1]=ret;
    }
}