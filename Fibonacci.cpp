#include<bits/stdc++.h>
using namespace std;
int fibIterative(int n){
    if(n<=1) return n;
    int a=0,b=1,c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int fibRecursive(int n){
    if(n<=1) return n;
    return fibRecursive(n-1)+fibRecursive(n-2);
}
int main(){
    while(true){
        cout<<"Enter 1 to print fibonacci number using recursion:"<<endl;
        cout<<"Enter 2 to print fibonacci number using iterative:"<<endl;
        cout<<"Enter 3 to print the fibonacci series:"<<endl;
        int op;
        cout<<"Enter the option:";
        cin>>op;
        if(op==1){
            int n;
            cout<<"Enter the value of n:";
            cin>>n;
            cout<<"Fibonacci number:"<<fibRecursive(n)<<endl;

        }else if(op==2){
            int n;
            cout<<"Enter the value of n:";
            cin>>n;
            cout<<"Fibonacci number:"<<fibIterative(n)<<endl;

        }else if(op==3){
            int n;
            cout << "Enter the number of terms: ";
            cin >> n;

            cout << "Fibonacci series: ";

            for(int i = 0; i < n; i++){
                cout << fibIterative(i) << " ";
            }

            cout << endl;
        }else {
            cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}