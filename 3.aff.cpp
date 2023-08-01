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
string encryption(string s,int k1,int k2)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        s[i]=(((s[i]-'a')*k1)+k2)%26+'A';
    }
    return s;
}
string decryption(string s, int k1, int k2)
{
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int x=(s[i]-'A'-k2);
        x=(x+26)%26;
        x*=k1;
        x%=26;
        s[i]=(x+'a');
    }
    return s;
}



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string plain_text;
    int key1,key2;
    cout<<"Enter the plain text and keys : ";
    cin>>plain_text>>key1>>key2;
    while(__gcd(26,key1)!=1)
    {
        cout<<"Invalid key1."<<endl<<"Enter valid key1: ";
        cin>>key1;
    }

    int z=modInv(key1);
    string cipher =encryption(plain_text,key1,key2);
    cout<< "Cipher Text is: "<<cipher<<endl;
    plain_text=decryption(cipher,z,key2);
    cout<<"Plain text is: "<<plain_text;

    return 0;

}
