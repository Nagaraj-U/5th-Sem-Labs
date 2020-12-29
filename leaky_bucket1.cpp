#include<iostream>
using namespace std;

int main()
{
    int rate,bucket_cap,bucket_rem,sent,recieved,n,dropped;
    cout << "enter number of packets" << endl;
    cin >> n;
    int * arr = new int[n];
    cout << "enter each packet size" << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "enter output rate" << endl;
    cin >> rate;
    cout << "enter bucket capacity : " << endl;
    cin >> bucket_cap;
    bucket_rem = 0;
    cout << "clock" << "  " << "packet" << "  " << "accepted" << "  " << "sent" << "  " << "remaining" << endl; 
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            if(bucket_rem + arr[i] > bucket_cap){
                recieved = -1;
            }else{
                recieved = arr[i];
                bucket_rem += arr[i];
            }
        }else{
            recieved = 0;
        }

        if(bucket_rem != 0){
            if(bucket_rem < rate){
                sent = bucket_rem;
                bucket_rem = 0;
            }else{
                sent = rate;
                bucket_rem = bucket_rem - rate;
            }
        }else{
            sent = 0;
        }
        if(recieved == -1){
            cout << (i+1) << "\t \t " << arr[i] << " \t\t " << "Dropped" << "\t\t  " << sent << "\t\t  " << bucket_rem << endl;
        }else{
            cout << (i+1) << "\t\t  " << arr[i] << "\t  \t" << recieved << "\t \t " << sent << "  \t\t" << bucket_rem << endl;
        }
    }
}