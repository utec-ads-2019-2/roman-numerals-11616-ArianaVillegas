#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<char,int> toArabic={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
map<int,char> toRoman={{1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'}};

string converttoRoman(string num){
    string newNum;
    int size=num.size(),n,base;
    for(int i=0;i<size;++i){
        n=int(num[i])-48;
        base=pow(10,size-i-1);
        if(n==9){newNum+=toRoman[base];base*=10;n=1;}
        if(n>5){newNum+=toRoman[5*base];n-=5;}
        if(n==4){newNum+=toRoman[base];++n;}
        if(n==5){newNum+=toRoman[5*base];n-=5;}
        for(int j=0;j<n;++j) newNum+=toRoman[base];
    }
    return newNum;
}

int converttoArabic(string num){
    int newNum=0;
    int size=num.size();
    for(int i=0;i<size-1;++i){
        if((num[i]=='I'&&(num[i+1]=='V'||num[i+1]=='X'))||(num[i]=='X'&&(num[i+1]=='L'||num[i+1]=='C'))||
        (num[i]=='C'&&(num[i+1]=='D'||num[i+1]=='M'))) newNum-=toArabic[num[i]];
        else newNum+=toArabic[num[i]];
    }
    return newNum+toArabic[num[size-1]];
}

int main() {
    string num;
    while(cin>>num) {
        if (isdigit(num[0])) cout << converttoRoman(num) << '\n';
        else cout << converttoArabic(num) << '\n';
    }
    return 0;
}