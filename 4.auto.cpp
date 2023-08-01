#include<bits/stdc++.h>
using namespace std;

string en(string s,int k)
{ 
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int temp=s[i]-'a';
        s[i]=(s[i]-'a'+k)%26+'A';
        k=temp;
    }
    return s;
}

string dn(string s,int k)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=(s[i]-'A'-k+26)%26+'a';
        k=s[i]-'a';
    }
    return s;
}



int main()
{
    string plain_text;
    int key;
    cout<<"Enter Plain Text: ";
    cin>>plain_text>>key;
    string cipher =en(plain_text,key);
    cout<<"Cipher Text: "<<cipher<<endl;
    plain_text=dn(cipher,key);
    cout<<"Plain text: "<<plain_text;
}
