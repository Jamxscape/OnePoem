//
//  main.cpp
//  writeMD
//
//  Created by 马元 on 2021/2/24.
//  关键难点汉字字符处理 读出1亿以下的数字

#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;
string pszNian[]={"","十","百","千","万","十","百","千","亿"};//如果还要加，还可以继续加
string pszShu[]={"零","一","二","三","四","五","六","七","八","九"};
// char *pszShu[]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};//这种方法用于银行的大写
string temp = "";
string f1(int a,int b)
{
    //cout<<a<<endl;
    if(a>=10)
        f1(a/10,b+1);
    if(a%10!=0){
        //cout<<temp + pszShu[a%10] + pszNian[b]<<endl;
        return temp = temp + pszShu[a%10] + pszNian[b];
    }
    else{
        //cout<<temp + pszShu[a%10]<<endl;
        return temp = temp + pszShu[a%10];
    }
    
}//递归
string replaceAll(string src, string regex, string replacement) {
    int length = regex.length();
    while(src.find(regex) < src.length()) {
        // 替换 src 字符串中从第一个匹配 regex 的字符串索引开始的 length 个字符为 replacement 字符串
        src.replace(src.find(regex), length, replacement);
    }
    return src;
}
string cleanZero(string s) {
    // 如果传入的是空串则继续返回空串
    if("" == s) {
        return "";
    }
    s = replaceAll(s, "零零", "零");//cout<<(s)<<endl;
    int len = s.size();
    string str;
    str = s.substr(len-3,3); //表示汉字“零”，经过测试得出, "\351\233\266"  在这里substr的位数是不确定的
    if(str == "零") //判断在这种情况下是否为这种的关系
        s.erase(len-3, 3);//如果末尾三位为汉字“零”，则删除后三位
    string str1;
    string str2;
    str1 = s.substr(0, 3);
    str2 = s.substr(3, 3);
    if(str1 == "一"&& str2 == "十")
        s.erase(0, 3); //解决读一十 一十万 一十二万等问题
    return s;
}
void f2(int n)
{
    string result;
    if(n<10000)
        result = cleanZero(f1(n,0));
    else if(n>=10000&n<100000000)
    {
        int n1 = n%10000;
        if(n1<1000){
            result ="零" + cleanZero(f1(n1,0));
            //cout<<"1"<<result<<endl;
        }else result = f1(n1,0);
        temp = "";
        int n2 = n/10000;
        result = cleanZero(f1(n2,0)) + "万" + result;
    }
    cout<<result;
    result = "";
    temp = "";
}
int main1(int argc, const char * argv[]) {
    for(int i=1;i<300;i++)
    {
        cout<<"[一首诗(其";
        f2(i);
        cout<<")](#"<<i<<")    ";
    }
//    f2(12000101); //测试用
    return 0;
}
