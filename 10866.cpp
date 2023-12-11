#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v;

void push_front(int num){
    v.insert(v.begin(),num);
}

void push_back(int num){
    v.push_back(num);
}

void front(){
    if(v.size()==0){
        cout<<-1<<'\n';
        return;
    }
    cout<< *v.begin()<<'\n';
}

void back(){
    if(v.size()==0){
        cout<<-1<<'\n';
        return;
    }
    cout<< *(v.end()-1)<<'\n';
}

void size(){
    cout<< v.size()<<'\n';
}

void empty(){
    if(v.size()==0)
        cout<<1<<'\n';
    else cout<<0<<'\n';
}

void pop_front(){
    if(v.size()==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<v[0]<<'\n';
    v.erase(v.begin());
}

void pop_back(){
    if(v.size()==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<*(v.end()-1)<<'\n';
    v.pop_back();
}

int main(){
    int n,temp;
    string order;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>order;
        if(order == "push_front"){
            cin>>temp;
            push_front(temp);
        }
        else if(order == "push_back"){
            cin>>temp;
            push_back(temp);
        }        
        else if(order == "pop_front"){
            pop_front();
        }
        else if(order == "pop_back"){
            pop_back();
        }
        else if(order == "front"){
            front();
        }
        else if(order == "back"){
            back();
        }
        else if(order == "size"){
            size();
        }
        else if(order == "empty"){
            empty();
        }
        else{
            cout<<"ERROR: WRONG INPUT\n";
        }
    }
    return 0;
}