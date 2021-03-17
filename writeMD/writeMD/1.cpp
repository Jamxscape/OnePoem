//
//  1.cpp
//  writeMD
//
//  Created by 马元 on 2021/3/10.
//

#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
using namespace std;
// 组合相加
long long int j(int n){
    long long int j = 1;
    for(int i = 1;i <= n; i++){
        j = j * i;
        cout<<j<<endl;
    }
    return j;
}
int main(){
    long long int sum = 0;
    int n;
    cin>>n;
//    for(int i = 1; i<= n; i++)
//    {
//        sum = sum + j(n)/(j(i)*j(n-i));
//    }
    sum = j(n);
    cout<<sum<<endl;
    return 0;
}
