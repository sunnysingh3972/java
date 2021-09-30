#include<iostream>
#include<climits>
using namespace std;
//using bruteforce approach
int main()
{
    int n,limit;
    cin>>n>>limit;
    int weight[n],value[n];
    //storing weight
    for(int i=0;i<n;i++)
        cin>>weight[i];
    //storing value
    for(int i=0;i<n;i++)
        cin>>value[i];
    int num_sub = (1<<n);
    int **ptr = (int**)calloc(num_sub,sizeof(int));
    for(int i=0;i<num_sub;i++)
    {
        *(ptr+i) = (int*)calloc(n,sizeof(int));
    }
    for(int i=0;i<num_sub;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                *(*(ptr+i)+j)=weight[j];
            }
        }
    }
    // cout<<"weight array"<<endl;
    int record_weight[num_sub],curr_sum=0,z=0;
    for(int i=0;i<num_sub;i++)
    {
        curr_sum=0;
        for(int j=0;j<n;j++)
        {
            // cout<<*(*(ptr+i)+j)<<" ";
            curr_sum+=*(*(ptr+i)+j);
        }
        record_weight[z++]=curr_sum;
        // cout<<endl;
    }
    // cout<<"weight record array"<<endl;
    for(int i=0;i<num_sub;i++)
    {
        // cout<<record_weight[i]<<" ";
    }
    // cout<<endl;
    int **ptr1 = (int**)calloc(num_sub,sizeof(int));
    for(int i=0;i<num_sub;i++)
    {
        *(ptr1+i) = (int*)calloc(n,sizeof(int));
    }
    int record_value[num_sub];
    z=0,curr_sum=0;
    for(int i=0;i<num_sub;i++)
    {
        curr_sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
            {
                *(*(ptr1+i)+j)=value[j];
                curr_sum+=*(*(ptr1+i)+j);
            }
        }
        record_value[z++]=curr_sum;
    }
    // cout<<"value array"<<endl;
    for(int i=0;i<num_sub;i++)
    {
        for(int j=0;j<n;j++)
        {
            // cout<<*(*(ptr1+i)+j)<<" ";
        }
        // cout<<endl;
    }
    // cout<<"record value array"<<endl;
    for(int i=0;i<num_sub;i++)
    {
        // cout<<record_value[i]<<" ";
    }
    int max_value=INT_MIN,count=0;
    for(int i=0;i<num_sub;i++)
    {
        if(record_weight[i]<=limit)
        {
            max_value=max(max_value,record_value[i]);
        }
    }
    //max value possible
    cout<<max_value;
    for(int i=0;i<num_sub;i++)
    {
        if(record_value[i]==max_value)
        {
            count=i;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(count&(1<<i))
        {
            cout<<weight[i]<<" ";
        }
    }
    return 0;
}