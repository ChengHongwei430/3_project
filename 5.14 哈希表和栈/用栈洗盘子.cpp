
#include<iostream>
#include<stack>

using namespace std;

int main() {

    stack<int> st;
    int n, x;

    cin >> n;
    while (n--) {
        cin >> x;
        st.push(x);
    }

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 1) {
            if (!st.empty()) st.pop();
        }
        else {
            cin >> x;
            st.push(x);
        }

    }
    if (st.empty()) cout << "All the dishes have been washed." << endl;
    else cout << st.top() << endl;
}