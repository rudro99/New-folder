#include<bits/stdc++.h>
using namespace std;

string encryption(string s,int k)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=(s[i]-'a'+k)%26+'A'; 
    }
    return s;
}

string decryption(string s,int k)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=(s[i]-'A'-k+26)%26+'a';
    }
    return s;
}





int main()
{
    //freopen("add_in.txt","r",stdin);
    //freopen("add_out.txt","w",stdout);

    string plain_text;
    int key;
    cout<<"Enter Plain text: ";
    cin>>plain_text>>key;
    string cipher =encryption(plain_text,key);
    cout<<"Cipher Text is: "<<cipher<<"\n";
    plain_text=decryption(cipher,key);
    cout<<"Plain Text is: "<<plain_text<<"\n";

}


