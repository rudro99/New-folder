#include<bits/stdc++.h>
using namespace std;


int modInv(int a) {
    a = a % 26;
    for (int i = 1; i < 26; i++) {
        if ((a*i) % 26 == 1)
            return i; 
    }
    return -1;
}
string encryption(string s,int k)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=((s[i]-'a')*k)%26+'A';
    }
    return s;
}

string decryption(string s,int k)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=((s[i]-'A')*k)%26+'a';
    }
    return s;
}


int main()
{
    //freopen("input","r",stdin);
    //freopen("input","r",stdin);

    string plain_text;
    int key;
    cout<<"Enter Plain text and key: ";
    cin>>plain_text>>key;
    while(__gcd(26,key)!=1)
    {
        cout<<"Invalid Key."<<"\n";
        cout<<"Enter valid key:";
        cin>>key;
    }

    int k1=modInv(key);
    string cipher=encryption(plain_text,key);
    cout<<"Cipher text is : "<<cipher<<"\n";
    plain_text=decryption(cipher,k1);
    cout<<"Plain text is : "<<plain_text<<"\n";



}
