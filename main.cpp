#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void elements (int& input, double& input2){
    cout<<"Please enter the number of elements:"<<endl;
    cin>>input;
while(cin.fail()){
    cout<<"***Please enter a number***."<<endl;
     cin.clear();
     cin.ignore();
     cin>>input;
}
    input2=input;
}
void menu (int &num){
    cout << "Please chose:" << endl;
    cout << "1 - addition" <<endl;
    cout << "2 - multiplication" <<endl;
    cout << "3 - average" <<endl;
    cout << "4 - square root" <<endl;
    cout << "5 - finish"<<endl;
    cin>>num;

    while(cin.fail()){
    cout<<"***Please enter a number***."<<endl;
     cin.clear();
     cin.ignore();
     cin>>num;
}
}

int random (int *arr, double& input){
    srand(time (NULL));
for (int i=0; i<input; i++){
    arr[i]=rand() % 11;
}

}

void show (int *arr, double& input2){
for (int i=0; i<input2; i++){
cout<< endl;
cout<<i+1<<". Number inside the array: " <<arr[i]<<"\t"<<endl;
}
}

void addition (int *arr, double&input2, double& add, double&toFile){
for (int i=0; i<input2; i++){
add+=arr[i];
}
toFile=add;
}

void multiplication (int *arr, int&input, int &mult, double&toFile){
    mult=1;
   for (int i=0; i<input; i++){
mult*=arr[i];
}
toFile=mult;
}

void average (double&input2,double&add, double aver, double&toFile){
   aver = add/input2;
   toFile=aver;

}

void squareRoot (int *arr, double&input2, double&sqr, double&toFile ){
    int max = -999999;
    for (int i=0; i<input2; i++){
        if (arr[i]>max){
            max=arr[i];
        }

    }
    sqr=sqrt(max);
    toFile=sqr;
}

void output (double& toFile){
  ofstream fout;
  fout.open("results.txt");
  fout <<"Answer: " <<toFile;
  fout.close();
  cout<<"Answer: "<<toFile<<endl;
}


int main(){
int input, mult, num;
double input2, add, aver, toFile, sqr;

elements (input, input2);
int arr[input];
random (arr,input2);
show (arr,input2);
menu2: cout<<endl;
menu (num);

if (num!=5){
switch (num){
case 1:
addition (arr,input2,add,toFile);
output(toFile);
add=0; toFile=0;

break;
case 2:

multiplication (arr,input,mult,toFile);
output(toFile);

break;
case 3:
addition (arr,input2,add,toFile);
average (input2,add,aver,toFile);
output(toFile);
add=0; toFile=0;
break;
case 4:
squareRoot (arr,input2,sqr,toFile);
output(toFile);
break;
}
goto menu2;
}
else{
cout<<"Program has been successfully finished"<<endl;
}
}
