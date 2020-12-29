#include<bits/stdc++.h>
using namespace std;

int main()
{
    string msg;
    string generator;
    cout << "enter message and generator" << endl;
    cin >> msg >> generator;
    int data_len = msg.length() + generator.length() - 1;
    int div_len = generator.length();
    int* data = new int[data_len]();
    int* divisor =  new int[div_len]();
    for(int i=0;i<msg.length();i++){
        data[i] = msg[i] - '0' ;
    }
    for(int i=0;i<generator.length();i++){
        divisor[i] = generator[i] -'0' ;
    }

    for(int i=0;i<msg.length();i++){
        if(data[i] == 1){
            for(int j=0;j<generator.length();j++){
                data[i+j] ^= divisor[j];
            }
        }
    }

    for(int i=0;i<msg.length();i++){
        data[i] = msg[i] - '0';
    }

   

    cout <<"msg is " << msg << "  " << "generator is : " << generator << endl;
    cout << "checksum is : " <<endl;
    for(int i=0;i<data_len;i++){
        cout << data[i] ;
    }

    cout <<" reciever side : " << endl;
    cout <<"enter checksum got in sender site " << endl;
    string checksum;
    cin >> checksum;
    int data_len1 = checksum.length() + generator.length() - 1 ;
    int* data1 = new int[data_len1]();
    for(int i=0;i<checksum.length();i++){
        data1[i] = checksum[i] - '0';
    }

    for(int i=0;i<checksum.length();i++){
        if(data1[i] == 1){
            for(int j=0;j<generator.length();j++){
                data1[i+j] ^= divisor[j];
            }
        }
    }

    // for(int i=0;i<checksum.length();i++){
    //     data1[i] = checksum[i] - '0';
    // }

    // cout << "checksum at reciever site is : " << endl;
    // for(int i=0;i<data_len1;i++){
    //     cout << data1[i] ;
    // }

    bool flag = true;
    for(int i=0;i<data_len1;i++){
        if(data1[i] == 1){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "datastream is valid" << endl;
    }else{
        cout << "datastream is invalid " << endl;
    }
    // for(int i=0;i<data_len;i++){
    //     cout << data[i] << "   " ; 
    // }
    // cout << endl;
    // for(int i=0;i<div_len;i++){
    //     cout << divisor[i] << "  " ;
    // }
    // cout << endl;
}