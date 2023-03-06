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

// void FCFS(){
//     cout<<"\n";
//     ll curr_time=0;
//     sort();
//     ll i=1;
//     while(i<=n){
//         if(curr_time<v[i].arrival_time){
//             cout<<"Idle Time from t = "<<curr_time<<" to t = "<<v[i].arrival_time<<endl;
//             curr_time=v[i].arrival_time;
//             continue;
//         }
//         else if(curr_time==v[i].arrival_time){
//             v[i].response_time=curr_time-v[i].arrival_time;
//             cout<<"At t = "<<curr_time<<" Process "<<v[i].pid<<" arrives"<<endl;
//             cout<<"Process "<<v[i].pid<<" executes from t = "<<curr_time<<" to t = "<<curr_time+v[i].burst_time<<endl;
//             curr_time+=v[i].burst_time;
//             v[i].completion_time=curr_time;
//             ++i;
//         }
//         else{
//             cout<<"At t = "<<curr_time<<" Process "<<v[i].pid<<" arrived"<<endl;
//         }

//     }
//     for(int i=1; i<=n; ++i){
//         v[i].turnaround_time=v[i].completion_time-v[i].arrival_time;
//         v[i].waiting_time=v[i].turnaround_time-v[i].burst_time;
//     }
//     sortPID();
// }

void FCFS(){
    cout<<"\n";
    ll curr_time=0;
    sort();
    // for(int i=1; i<=n; ++i)cout<<v[i].pid<<" ";
    cout<<endl;
    ll i=1;
    queue<ll> q;
    // cout<<"At t = "<<curr_time<<" :\n";
    // for(i=1; i<=n; ++i){
    //     if(v[i].arrival_time==curr_time){
    //         cout<<"Process "<<v[i].pid<<" arrives\n";
    //         q.push(i);
    //     }
    //     else break;
    // }
    // if(q.empty()){
    //     cout<<"CPU is Idle, no process in the ready queue.\n";
    //     curr_time=v[1].arrival_time;
    // }
    // while(i<=n){
    //     cout<<"At t = "<<curr_time<<" :\n";
    //     for(int j=i; j<=n; ++j){
    //         if(v[j].arrival_time<=curr_time)q.push(j);
    //     }
    // }
    while(i<=n){
        for(int j=i; j<=n; ++j){
            if(v[j].arrival_time<=curr_time){
                cout<<"At t = "<<v[j].arrival_time<<" Process "<<v[j].pid<<" arrives\n";
                q.push(j);
                if(j==n)++i;
            }
            else{
                i=j;
                break;
            }
        }
        if(q.empty()){
            cout<<"CPU is Idle, no process in the ready queue.\n";
            // cout<<i<<endl;
            curr_time=v[i].arrival_time;
        }
        else{
            while(!q.empty() && i<=n){
                ll execProcess=q.front();
                cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" begins its execution\n";
                q.pop();
                v[execProcess].response_time=curr_time-v[execProcess].arrival_time;
                if(curr_time+v[execProcess].burst_time<v[i].arrival_time){
                    curr_time+=v[execProcess].burst_time;
                    v[execProcess].completion_time=curr_time;
                    cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                }
                else if(curr_time+v[execProcess].burst_time==v[i].arrival_time){
                    curr_time+=v[execProcess].burst_time;
                    v[execProcess].completion_time=curr_time;
                    cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                    cout<<"At t = "<<v[i].arrival_time<<" Process "<<v[i].pid<<" arrives\n";
                    q.push(i);
                    ++i;
                }
                else{
                    curr_time+=v[execProcess].burst_time;
                    v[execProcess].completion_time=curr_time;
                    cout<<"At t = "<<v[i].arrival_time<<" Process "<<v[i].pid<<" arrives\n";
                    q.push(i);
                    ++i;
                    cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" completes its execution\n";
                }
            }
            while(!q.empty()){
                ll execProcess=q.front();
                cout<<"At t = "<<curr_time<<" Process "<<v[execProcess].pid<<" begins its execution\n";
                q.pop();
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
    cout<<"First Come First Served (FCFS)"<<"\n\n";
    input();
    FCFS();
    output();
}