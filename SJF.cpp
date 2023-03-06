#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;

struct process{
    ll pid;
    ll arrival_time;
    ll burst_time;
    ll completion_time;
    ll turnaround_time;
    ll waiting_time;
    ll response_time;
}v[10001];

void input(){
    cout<<"Enter number of processes to be scheduled : ";
    cin>>n;
    cout<<"\nEnter process id, arrival time and burst time:-\n";
    for(int i=1; i<=n; ++i){
        cin>>v[i].pid>>v[i].arrival_time>>v[i].burst_time;
    }
}

void output(){
    cout<<"\n---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for(int i=1; i<=n; ++i)cout<<v[i].pid<<"\t"<<v[i].arrival_time<<"\t"<<v[i].burst_time<<"\t"<<v[i].completion_time<<"\t"<<v[i].turnaround_time<<"\t"<<v[i].waiting_time<<"\t"<<v[i].response_time<<endl;
    cout<<"\n--------------------------------------------------------------------------------------------------"<<endl;
}

void sort(){
    // bubble sort to sort the array of structs
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n-i; ++j){
            if(v[j].arrival_time>v[j+1].arrival_time){
                swap(v[j],v[j+1]);
            }
            else if(v[j].arrival_time==v[j+1].arrival_time){
                if(v[j].pid>v[j+1].pid){
                    swap(v[j],v[j+1]);
                }
            }
        }
    }
}

void sortPID(){
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n-i; ++j){
            if(v[j].pid>v[j+1].pid){
                swap(v[j],v[j+1]);
            }
        }
    }
}

void SJF(){
    cout<<"\n";
    ll curr_time=0;
    sort();
    // for(int i=1; i<=n; ++i)cout<<v[i].pid<<" ";
    cout<<endl;
    ll i=1;
    multiset<pair<ll,ll>> ms;
    while(i<=n){
        for(int j=i; j<=n; ++j){
            if(v[j].arrival_time<=curr_time){
                cout<<"At t = "<<v[j].arrival_time<<" Process "<<v[j].pid<<" arrives\n";
                ms.insert({v[j].burst_time, j});
                if(j==n)i=n+1;;
            }
            else{
                i=j;
                break;
            }
        }
        if(ms.empty()){
            cout<<"CPU is Idle, no process in the ready queue.\n";
            // cout<<i<<endl;
            curr_time=v[i].arrival_time;
        }
        else{
            while(!ms.empty() && i<=n){
                auto it=ms.begin();
                ll execProcess=it->second;
                cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" begins its execution\n";
                ms.erase(it);
                v[execProcess].response_time=curr_time-v[execProcess].arrival_time;
                if(curr_time+v[execProcess].burst_time<v[i].arrival_time){
                    curr_time+=v[execProcess].burst_time;
                    v[execProcess].completion_time=curr_time;
                    cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                }
                // else if(curr_time+v[execProcess].burst_time==v[i].arrival_time){
                //     curr_time+=v[execProcess].burst_time;
                //     v[execProcess].completion_time=curr_time;
                //     cout<<"At t = "<<v[i].arrival_time<<" Process "<<v[i].pid<<" arrives\n";
                //     ms.insert({v[i].burst_time, i});
                //     ++i;
                //     cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                // }
                else{
                    curr_time+=v[execProcess].burst_time;
                    v[execProcess].completion_time=curr_time;
                    for(int j=i; j<=n; ++j){
                        if(v[j].arrival_time<=curr_time){
                            cout<<"At t = "<<v[j].arrival_time<<" Process "<<v[j].pid<<" arrives\n";
                            ms.insert({v[j].burst_time, j});
                            if(j==n)i=n+1;;
                        }
                        else{
                            i=j;
                            break;
                        }
                    }
                    cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                }
            }
            while(!ms.empty()){
                auto it=ms.begin();
                ll execProcess=it->second;
                cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" begins its execution\n";
                ms.erase(it);
                v[execProcess].response_time=curr_time-v[execProcess].arrival_time;
                curr_time+=v[execProcess].burst_time;
                v[execProcess].completion_time=curr_time;
                cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
            }
        }
    }
    for(int i=1; i<=n; ++i){
        v[i].turnaround_time=v[i].completion_time-v[i].arrival_time;
        v[i].waiting_time=v[i].turnaround_time-v[i].burst_time;
    }
    sortPID();
}

int main(){
    cout<<"Shortest Job First (SJF)"<<"\n\n";
    input();
    SJF();
    output();
}