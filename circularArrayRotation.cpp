#include<iostream>
#include<vector>
using namespace std;
vector<int> circularArrayRotation(vector<int> array,int k,vector<int> query)
{
    vector<int> result;
    for(int i=0;i<k;i++)
    {
        array.insert(array.begin(),*(array.end()-1));
        array.erase(array.end()-1);
    }
    for(int i=0;i<query.size();i++)
    {
        result.push_back(array[query[i]]);
    }
    return result;
}
int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> array;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        array.push_back(temp);
    }
    vector<int> query;
    for(int j=0;j<q;j++)
    {
        int temp;
        cin>>temp;
        query.push_back(temp);
    }

    vector<int>result = circularArrayRotation(array,k,query);
    for(int i=0;i<query.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
