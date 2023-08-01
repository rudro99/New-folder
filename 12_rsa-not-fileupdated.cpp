#include <bits/stdc++.h>
using namespace std;

int public_key;
int private_key;
int n;


bool isPrime(int p)
{
    if (p <= 1)
        return false; 

    for (int i = 2; i <= p / 2; i++)
        if (p % i == 0)
            return false;

    return true;
}




void setkeys(int p1, int p2)
{
    n = p1 * p2;
    int fi = (p1-1)*(p2-1);
    int e = 2;
    while (__gcd(e, fi) != 1)
        e++;
    public_key = e;

    int d = 2;
    while ((d * e) % fi != 1)
        d++;
    private_key = d;
}
long long encrypt(long long p)
{
    int e = public_key;
    long long enc = 1;

    while (e--)
        enc = (enc * p) % n;

    return enc;
}
long long decrypt(int c)
{
    int d = private_key;
    long long dec = 1;
    while (d--)
        dec = (dec * c) % n;

    return dec;
}

int main()
{
    int p1, p2;
    cout << "Enter two prime numbers: ";
    cin >> p1 >> p2;

    bool a=isPrime(p1);
    if(!a)
    {
        cout<<p1<<" is not prime.";
        return 0;
    }
    bool b=isPrime(p2);
    if(!b)
    {
        cout<<p2<<" is not prime.";
        return 0;
    }




    setkeys(p1, p2);

    cout << "Public Key: " << public_key << endl;
    cout << "Private Key: " << private_key << endl;

    long long p;
    cout << "Enter the plaintext: ";
    cin >> p;

    long long cipher = encrypt(p);
    cout << "Ciphertext: " << cipher << endl;

    cout << "Plaintext: " << decrypt(cipher) << endl;
    return 0;
}
