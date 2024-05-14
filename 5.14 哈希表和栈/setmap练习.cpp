
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>//不要忘记unordered_set之间的横杠
using namespace std;

//set、map增加不同，set用insert,map用map[first]=second;
//删除相同，都用erase(first)
//遍历都是迭代器，unordered_set<int>::iterator i
//begin() end()


int main() {

    //srand(time(NULL));

    //unordered_set<int> myset;//无序哈希表

    //for (int i = 1; i < 10; ++i) myset.insert(i);//将1-9输入
    //for(int i = 1; i < 10; ++i) {
    //    int a = rand()%9;//随机函数rand可以生成随机范围的整数值
    //    //cout << a << endl;
    //    if (rand() % 9 > 5)
    //        myset.erase(i);
    //}
    //for (unordered_set<int>::iterator i = myset.begin(); i != myset.end(); ++i) {
    //    cout << *i << endl;
    //}

    srand(time(NULL));

    unordered_map<char,int> mymap;//无序哈希表

    //添加
    for (int i = 1; i < 10; ++i) {
        char a = 'a' + i;
        //mymap[a]=i;
        mymap.insert(make_pair(a, i));
    }

    //遍历
    for (unordered_map<char,int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        cout << i->first<< i->second <<" ";
    }
    cout<<endl;

    //删除
    for (int i = 1; i < 10; ++i) {
        int a = rand() % 9;//随机函数rand可以生成随机范围的整数值
        //cout << a << endl;
        if (rand() % 9 > 5) mymap.erase('a'+i);//只能从i->first来删除
    }

    //遍历
    for (unordered_map<char, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        cout << i->first << i->second << " ";
    }
    cout << endl;
    
    

    system("pause");
    
}