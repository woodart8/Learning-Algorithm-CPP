#include <iostream>
#include <vector>
using namespace std;

vector<int> node;
vector<vector<int>> child;
vector<int> parent;

void delNode(int del){
    for(int i=0; i<child[del].size();){
        delNode(child[del][i]);
    }
    child[del].clear();

    for(int i=0; i<node.size(); i++){
        if(node[i]==del){
            node.erase(node.begin()+i);
            break;
        }
    }
    
    if(parent[del]!=-1){
        for(int i=0; i<child[parent[del]].size(); i++){
            if(child[parent[del]][i]==del){
                child[parent[del]].erase(child[parent[del]].begin()+i);
                break;
            }
        }
    }
}

int leafNode(){
    int count = 0;
    for(auto iter: node){
        if(child[iter].size() == 0){
            count++;
        }
        for(int i=0; i<child[iter].size(); i++){
            cout<<"child of "<<iter<<" = "<<child[iter][i]<<'\n';
        }
    }
    return count;
}

int main(){
    int n,tmp,del;
    cin>>n;

    for(int i=0; i<n; i++){
        vector<int> v;
        child.push_back(v);
        node.push_back(i);        
    }

    for(int i=0; i<n; i++){
        cin>>tmp;
        parent.push_back(tmp);
        if(tmp!=-1){
            child[tmp].push_back(i);
        }
    }

    cin>>del;
    delNode(del);
    cout<<leafNode();
    return 0;
}