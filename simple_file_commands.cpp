#include <bits/stdc++.h>

using namespace std;

typedef list<int> lst;
map<string,lst> files;

int createFile(char* &its, bool rnm = false){
    map<string,lst>::iterator it = files.find(its);
    int pos = 0;
    if(it != files.end()){
        list<int>::iterator it_l =it->second.begin();
        if(it->second.size() > 1){
            *it_l += 1;
            pos = *(++it_l);
            it->second.erase(it_l);
        }
        else{
            *it_l += 1;
            pos = *it_l;
        }
    }else{
        lst list;
        list.push_back(0);
        files.insert(pair<string,lst> (its,list));
        it = files.find(its);
    }
    if(rnm)
        cout <<" -> "<<it->first;
    else
        cout <<"+ "<<it->first;
    if(pos)
        cout <<"("<<pos<<")";
    return 0;
}

int deleteFile(char* &its, bool rnm = false){
    map<string,lst>::iterator it =  files.find(its);
    list<int>::iterator it_l =
        it->second.begin();
    its = strtok(NULL,") ");
    char *sub = strtok(NULL," ");
    int val = 0;
    if(sub){
        val = atoi(its);
        its = sub;
    }else if(its && !rnm)
        val = atoi(its);
    *it_l -= 1;
    it_l++;
    for(it_l;it_l != it->second.end();it_l++){
        if(val < *it_l){
            it->second.insert(it_l,val);
            break;
        }
    }
    if(it_l == it->second.end()){
        it->second.insert(it_l,val);
    }
    if(rnm)
        cout <<"r "<<it->first;
    else
        cout <<"- "<<it->first;
    if(val)
        cout<<"("<<val<<")";
    return 0;
}

int filesystem(string &s){
    char *cmd = strdup(s.c_str());
    char *its = strtok(cmd," ");
    switch(*its){
        case 'c':{
             its = strtok(NULL,"(");
             createFile(its);
             cout<<endl;
            break;
        }
        case 'd':{
            its = strtok(NULL,"(");
            deleteFile(its);
            cout<<endl;
            break;
        }
        case 'r':{
            its = strtok(NULL,"( ");
            deleteFile(its,true);
            createFile(its, true);
            cout<<endl;
            break;
        }
    }
    return 0;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string command;
        std::getline(std::cin >> std::ws,command);
        filesystem(command);
    }
    return 0;
}

