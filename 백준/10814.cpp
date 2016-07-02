#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int i, num;
    string s; 
    queue<string> que[201];
    
    cin >> i;
    for(int k = 0; k<i; k++){
    	cin >> num >> s;
    	que[num].push(s);
    }
    
    for(int k = 1; k<=200; k++){
    	while(!que[k].empty()){
    		cout << k << " " << que[k].front() << endl;
    		que[k].pop();
    	}
    }
    
    return 0;
}