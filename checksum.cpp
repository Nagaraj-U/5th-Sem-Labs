#include<bits/stdc++.h>
using namespace std;
int carry = 0;
//ctrl+shift+l to select multiple cursors

int comp(int a){
    if(a == 1){
        return 0;
    }else{
        return 1;
    }
}

int add(int a,int b)
{
        
        if(a == 0 && b == 0 && carry == 0){
            carry = 0;
            return 0;   
        }else if(a == 0 && b == 0 && carry == 1){
            carry = 0;
            return 1;
         
        }else if(a == 1 && b == 1 && carry == 0){
            carry = 1;
            return 0;
            
        }else if(a == 1 && b == 1 && carry == 1){
             carry = 1;
            return 1;
           
        }else if(a == 0 && b == 1 && carry == 0){
            carry = 0;
            return 1;
            
        }else if(a == 0 && b == 1 && carry == 1){
            carry = 1;
            return 0;
            
        }else if(a == 1 && b == 0 && carry == 0){
            carry = 0;
            return 1;
            
        }else if(a == 1 && b == 0 && carry == 1){
            carry = 1;
            return 0;
            
        }
}
bool rec_check(int* data1,int* data2,int len){
    int* newdata = new int[len];
    int* checksum = new int[len];
    int* complement = new int[len];
    

     for(int i=len-1;i>=0;i--){
        newdata[i] = add(data1[i],data2[i]);
    }

    if(carry == 1){
        for(int i=len-1;i>=0;i--){
            if(i == len-1){
                 newdata[i] = add(newdata[i],1);
            }else{
                 newdata[i] = add(newdata[i],0);
            }
           
        }
    }

    for(int i=0;i<len;i++){
        complement[i] = comp(newdata[i]);
    }

    cout << "sum is " << endl;
    for(int i=0;i<len;i++){
        cout << newdata[i];
    }
    cout << endl;

    cout << "checksum is " << endl;
    for(int i=0;i<len;i++){
        cout << complement[i];
    }
    cout << endl;

    bool flag = true;
    for(int i=0;i<len;i++){
        if(complement[i] == 1){
            return false;
        }
    }
    return true;

}

int main()
{
    string a;
    string b;
    cout << "enter two strings" << endl;
    cin >> a >> b;
    int len = a.length();
    int* data1 = new int[len];
    int* data2 = new int[len];
    int* checksum = new int[len];
    int* complement = new int[len];
    int* newdata = new int[len];

    for(int i=0;i<len;i++){
        data1[i] = a[i] - '0';
        data2[i] = b[i] - '0';
    }

    for(int i=len-1;i>=0;i--){
        newdata[i] = add(data1[i],data2[i]);
    }

    for(int i=0;i<len;i++){
        complement[i] = comp(newdata[i]);
    }

    cout << "sum is " << endl;
    for(int i=0;i<len;i++){
        cout << newdata[i];
    }
    cout << endl;

    cout << "checksum is " << endl;
    for(int i=0;i<len;i++){
        cout << complement[i];
    }
    cout << endl;
  
  cout<< "RECIEVER SIDE INFO" << endl;

    //FOR TESTING (ALTER ONE BIT)

    // if(newdata[1] == 1){
    //     newdata[1] = 0;
    // }else{
    //     newdata[1] = 1;
    // }

    bool ans = rec_check(newdata,complement,len);
    if(ans){
        cout << "data recieved correctly" << endl;
    }else{
        cout << "data corrupted" << endl;
    }
    cout << endl;
}


/*

make sure you add one extra 0 in left most bit to avoid carry 

*/