#include<bits/stdc++.h>
using namespace std;

int getalpha(int p)
{
    int** arr = new int*[p]();
    for(int i=1;i<p;i++){
        arr[i] = new int[p];
    }
    
    for(int i=1;i<p;i++){
        map<int,int> m;
        for(int j=1;j<p;j++){
            long ans = pow(i,j);
            arr[i][j] = (ans%p);
            m[arr[i][j]] += 1;
        }
        bool flag = true;
        for(int k=1;k<p;k++){
            
            if(m[k] == 0){
                flag = false;
            }
        }
        if(flag){
            return i; 
        }
    }
    return 0;
}

int get_public(int alpha,int private_n,int p){
    long long temp = pow(alpha,private_n);
    return (temp%p);
}

int get_key(int private_n,int public_n,int p){
    long long temp = pow(public_n,private_n);
    return (temp%p);
}

int main()
{
    int p = 13;
    //int alpha = 2;
    int alpha =  getalpha(p);
    int private_a = 8;
    int private_b = 4;
    int public_a = get_public(alpha,private_a,p);
    int public_b = get_public(alpha,private_b,p);

    int key_a = get_key(private_a,public_b,p);
    int key_b = get_key(private_b,public_a,p);

  
    cout <<"alpha is " << getalpha(p) << endl;

    cout <<"key at A " << key_a << endl; 
    cout <<"key at B " << key_b << endl; 
}