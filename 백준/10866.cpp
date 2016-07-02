#include<iostream>
#include<deque>
#include<cstring>

using namespace std;

int main(void){
	int num, X;
	char s[15];
	deque<int> que;
	
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> s;
		if(strcmp(s, "push_front") == 0){
			cin >> X;
			que.push_front(X);
		}
		else if(strcmp(s, "push_back") == 0){
			cin >> X;
			que.push_back(X);
		}
		else if(strcmp(s, "pop_front") == 0){
			if(!que.empty()){
				cout << que.front() << endl;
				que.pop_front();
			}
			else{
				cout << "-1" << endl;
			}
		}
		else if(strcmp(s, "pop_back") == 0){
			if(!que.empty()){
				cout << que.back() << endl;
				que.pop_back();
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