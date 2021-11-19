#include <bits/stdc++.h>

using namespace std;

typedef struct gift {
    char code;
    int val;
} gift;

int bonus(int x,int y,int prio) {
    float c=0;
    c += x;
    c += y;
    if (prio == 3) c += 16.0 / 100.0 * (float)(x+y);
    if (prio == 2) c += 8.0 / 100.0 * (float)(x+y);
    if (prio == 1) c += 4.0 / 100.0 * (float)(x+y);
    return (int)c;
}

gift cal(vector<gift> lists) {
    gift out;
    out.code = '-';
    for (int i=1;i<lists.size();i+=2) {
        if (lists[i].code == '3') {
            int tmp = bonus(lists[i-1].val,lists[i+1].val,3);
            lists[i-1].val = tmp;
            lists[i+1].val = tmp;
            out.val = tmp;
        }
    }
    for (int i=1;i<lists.size();i+=2) {
        if (lists[i].code == '2') {
            int tmp = bonus(lists[i-1].val,lists[i+1].val,2);
            lists[i-1].val = tmp;
            lists[i+1].val = tmp;
            out.val = tmp;
        }
    }
    for (int i=1;i<lists.size();i+=2) {
        if (lists[i].code == '1') {
            int tmp = bonus(lists[i-1].val,lists[i+1].val,1);
            lists[i-1].val = tmp;
            lists[i+1].val = tmp;
            out.val = tmp;
        }
    }
    return out;
}



int main()
{
    string in;
    cin >> in;
    vector<gift> lists;
    for (int i=0;i<in.size();i++) {
        gift news;
        news.code = in[i];
        news.val = 20;
        lists.push_back(news);
    }

    stack<gift> st;
    int flag = 0;
    for (gift i : lists) {
        if (i.code == ']') {
            flag--;
            vector<gift> n_list;
            while (st.top().code != '[') {
                n_list.insert(n_list.begin(),st.top());
                st.pop();
            }
            st.pop();
            gift news2 = cal(n_list);
            st.push(news2);
        } else st.push(i);
    }
    /*
    stack<gift> st2 = st;
    while (!st2.empty()) {
        cout << st2.top().code << " " << st2.top().val << endl;
        st2.pop();
    }
    */
    vector<gift> n_list;
    while (!st.empty()) {
        gift news3 = st.top();
        st.pop();
        n_list.insert(n_list.begin(),news3);
    }
    cout << cal(n_list).val << endl;

    return 0;
}
