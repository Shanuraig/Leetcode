#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
bool check (vector<int> &tasks, vector<int> &workers, int pills,
    int strength,int mid){
        multiset<int> st(begin(workers),begin(workers)+mid);
        int usedpills=0;
        for(int i=mid-1;i>0;i--){
            int req=tasks[i];
            auto avail=prev(st.end());
            if(*avail>=req){
                st.erase(avail);
            }
            else if (usedpills>=pills){
                    return false;
            }
            else{
                auto it =st.lower_bound(tasks[i]-strength);
                if(it==st.end()){
                    return false;
                }
                st.erase(it);
                usedpills++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                      int strength)
    {
        int t=tasks.size();
        int w=workers.size();
        int res=0;
        sort(begin(tasks),end(tasks));
        sort(begin(workers),end(workers), greater<int>());
        int low=0,high=min(t,w);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(tasks,workers,pills,strength,mid)){
                res=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};