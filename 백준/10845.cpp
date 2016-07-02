#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int main(void){
	int num, X;
	char s[10];
	queue<int> que;
	
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> s;
		if(strcmp(s, "push") == 0){
			cin >> X;
			que.push(X);
		}
		else if(strcmp(s, "pop") == 0){
			if(!que.empty()){
				cout << que.front() << endl;
				que.pop();
			}
			else{
				cout << "-1" << endl;
			}
		}
		else if(strcmp(s, "size") == 0){
			cout << que.size() << endl;
		}
		else if(strcmp(s, "empty") == 0){
			if(!que.empty()){
				cout << "0" << endl;
			}
			else{
				cout << "1" << endl;
			}
		}
		else if(strcmp(s, "front") == 0){
			if(!que.empty()){
				cout << que.front() << endl;
			}
			else{
				cout << "-1" << endl;
			}
		}
		else{
			if(!que.empty()){
				cout << que.back() << endl;
			}
			else{
				cout << "-1" << endl;
			}
		}
	}
}