#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a<b){
        return gcd(b,a);
    }
    if(b == 0){
        return a;
    }
    if(a == 0){
        return b;
    }
    return gcd(b,a%b);
}

int calculateE(int n,int phi){
    int e;
    for(int i=2;i<phi;i++){
        if(gcd(i,phi) == 1){
            e = i;
            return e;
        }
    }
    return 0;
}

int calculateD(int n,int phi,int e)
{
    int d;
    for(int i=2;i<phi;i++){
        int temp = (i * e);
        if((temp % phi) == 1){
            d = i;
            return d;
        }  
    }
    return 0;
}

long long cipherText(int msg,int e,int n){
    long long c;
    long long temp = pow(msg,e);
    c = (temp % n);
    return c;
}

int decryption(long long c,int d,int n){
    long long temp;
    temp = pow(c,d);
    int ans = (temp % n);
    return ans;
}

int main()
{
    int p = 11;
    int q = 3;
    int n = (p*q);
    int phi = ((p-1)*(q-1));
    int e,d;
    e = calculateE(n,phi);
    d = calculateD(n,phi,e);
    int msg;
    cout << "enter message " << endl;
    cin >> msg; 
    //encryption
    long long c = cipherText(msg,e,n);
    int ans = decryption(c,d,n);
    cout <<"p is : " << p << endl;
    cout <<"q is : " << q << endl;
    cout << "n is : " << n << endl;
    cout << "totient is : " << phi << endl; 
    cout << "public key : " << e << endl;
    cout << "private key : " << d << endl;
    cout << "user message : " << msg << endl;
    cout << "encrypted message : " << c << endl;
    cout << "decrypted message : " << ans << endl;
    return 0;
}

/*

enter message 
29
p is : 11
q is : 3
n is : 33
totient is : 20
public key : 3
private key : 7
user message : 29
encrypted message : 2
decrypted message : 29




enter message 
15
p is : 11
q is : 3
n is : 33
totient is : 20
public key : 3
private key : 7
user message : 15
encrypted message : 9
*/
