#include<bits/stdc++.h>
using namespace std;

map<char,char> encMap,decMap;
string en(string s)
{ 
    string cipher="";
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        cipher +=encMap[s[i]];
    }
    return cipher;
}

string dn(string s)
{
    string plain="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        plain +=decMap[s[i]];
    }
    return plain;
}


int main()
{
    freopen("abc.txt","r",stdin);

    for(int i=0;i<26;i++)
    {
        char a,b;
        cin>>a>>b;
        encMap[a]=b;
        decMap[b]=a;
    }

    string plain_text;
    cin>>plain_text;

    string cipher=en(plain_text);
    cout<<"Cipher Text is: "<<cipher<<endl;
    plain_text=dn(cipher);
    cout<<"Plain Text is: "<<plain_text;
    return 0;
}
