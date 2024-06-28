#include "json.hpp"
using json = nlohmann :: json;

#include <iostream>
#include <vector>
#include <map>
#include<string>
using namespace std;

// json序列化示例1
string func1() {
    json js;
    js["msg_type"] = 2;
    js["from"] = "zhang san";
    js["to"] = "li si";
    js["msg"] = "hello.how are u?";
    
    string sendBuf = js.dump();  // json数据对象 =》序列化 json字符串
    // cout << sendBuf.c_str() <<endl;
    return sendBuf;

}

// json序列化示例2
string func2() {
    json js;

    // 直接序列化一个vector容器 
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(21);
    vec.push_back(2);

    js["list"] = vec;

    // 直接序列化一个map容器
    map<int,string>m;
    m.insert({1,"华山"});
    m.insert({2,"黄山"});

    js["path"] = m;

    string sendBuf = js.dump();
    // cout << sendBuf << endl;
    return sendBuf;
}
int main() {

    // func1();
    // func2();

    // string recvBuf = func1();
    // // 数据的反序列化 json字符串 =》反序列化 数据对象（看作容器，方便访问）
    // json jsbuf = json :: parse(recvBuf);
    // cout<<jsbuf["msg_type"]<<endl;
    // cout<<jsbuf["from"]<<endl;
    // cout<<jsbuf["to"]<<endl;
    // cout<<jsbuf["msg"]<<endl;

    string recvBuf = func2();
    json jsbuf = json :: parse(recvBuf);
    vector<int>vec = jsbuf["list"];
    for(auto &v : vec)
    {
        cout<< v << " ";
    }
    cout<<endl;

    map<int,string>mymap  = jsbuf["path"];
    for(auto &p :mymap)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}