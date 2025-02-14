#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool compare(const pair<int,int>&a,const pair<int,int>& b)
{
    if (a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second<b.second;  
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n;
    cin>>n;
    map<int,int>baln;
    for(int i=0;i<n;i++)
    {
        int id;
        int bal;
        cin>>id>>bal;
        baln[id]=bal;
    }
    int t;
    cin >> t;
    vector<string>stats;
    for (int i=0;i<t;++i)
    {
        int fromuid;
        int touid;
        int amt;
        cin>>fromuid>>touid>>amt;
        if (baln[fromuid]>=amt) 
        {
            baln[fromuid]-=amt;
            baln[touid]+=amt;
            stats.push_back("Success");
        } 
        else
        {
            stats.push_back("Failure");
        }
    }
    for(const auto&p:stats) {
        cout<<p<<endl;
    }
    cout<<endl;
    vector<pair<int,int>>ulist(baln.begin(),baln.end());
    sort(ulist.begin(),ulist.end(), compare);
    for(const auto&u:ulist) {
        cout<<u.first<<" "<<u.second<<endl;
    }
    return 0;
}