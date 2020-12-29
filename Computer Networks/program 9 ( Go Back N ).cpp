#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int window_size,no_frames,i;
    int frames[50];
    cout << "enter number of frames to be sent : " << endl;
    cin >> no_frames;
    cout << "enter window size " << endl;
    cin >> window_size;
    cout << "enter frame numbers" <<endl;
    for(i=1;i<=no_frames;i++){
        cin >> frames[i];
    }
    for(i=1;i<=no_frames;i++){
        if((i % window_size) == 0){ //window is full after ack window size decreses by 1
            cout << frames[i] << " " << endl;
            cout << "acknowledgement for above frames is recieved by sender"<< endl;
        }else{
            cout << frames[i] <<  " " ;
        }
    }
    if((no_frames % window_size) != 0){
        cout << "\nacknowledgement for above frames is recieved by sender"<< endl;
    }
    return 0;
}
