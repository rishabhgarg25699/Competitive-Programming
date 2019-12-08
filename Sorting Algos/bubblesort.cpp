void bubblesort(int mylist[])
{
    int k=1;
    while (k==1)
        {
            k=0;
            for (i=1;i<=n;i++)
            {
                if (mylist[i]>=mylist[i-1])
                {
                    temp=mylist[i];
                    mylist[i]=mylist[i-1];
                    mylist[i-1]=temp;
                    k=1;
                }
            }
        }
}
