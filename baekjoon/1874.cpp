#include<iostream>
#include<stack>

using namespace std;

int bae[200000];

int main(void){
    int i, num=0, check=0, finish=1;
    stack<int> st;
    st.push(num);
    num++;
    cin >> i;
    for(int k = 0; k<i; k++){
        int j;
        cin >> j;
        while(st.top() < j){
            st.push(num);
            bae[check++] = 0;
            num++;
        }
        if(st.top() == j){
            st.pop();
            bae[check++] = 1;
        }
        else{
            cout << "NO" << endl;
            finish = 0;
            break;
        }
    }
    if(finish == 1){
        for(int k = 0; k<check; k++){
			if(bae[k] == 0){
				cout << "+" << endl;
			}
			else{
				cout << "-" << endl;
			}
        }
    }
    
    return 0;
}