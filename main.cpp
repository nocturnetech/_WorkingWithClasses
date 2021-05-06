#include <iostream>
#include <fstream>

using namespace std;

struct people {
string name;
string lastName;
int unsigned birthDate;
string city;
string gender;
}

arr [10];
int i, j, personNumber=1;

void infoWithI(){
    cout<<arr[i].name<<" ";
    cout<<arr[i].lastName<<" ";
    cout<<arr[i].birthDate<<" ";
    cout<<arr[i].city<<" ";
    cout<<arr[i].gender<<" "<<endl;
}

void infoWithJ(){
    cout<<arr[j].name<<" ";
    cout<<arr[j].lastName<<" ";
    cout<<arr[j].birthDate<<" ";
    cout<<arr[j].city<<" ";
    cout<<arr[j].gender<<" "<<endl;
}

void thisResult () {
cout<<"***The results have been transferred to results.txt file***"<<endl;
}

void emptySpace () {
cout<<endl;
}

void cityError () {
cout<<"\n***The city you entered is either:***\n   - Not from the list\n   - Written in lower case\n   - Has a typo"<<endl;
cout<<"***Please enter the city from the list with the first letter capitalized (example: London)***"<<endl;
}

int main()
{
int menu, option=0, maxNumber=99999, theEnd=0, theEnd2=0;
string inputCity;

ifstream fin;

fin.open("residents.txt");
for (i=0;i<10;i++){
    fin>>arr[i].name;
    fin>>arr[i].lastName;
    fin>>arr[i].birthDate;
    fin>>arr[i].city;
    fin>>arr[i].gender;
}
fin.close();

for (i=0;i<10;i++){
    infoWithI();
}

do{
cout << endl
<< " 1 - Shows the oldest person on the list.\n"
<< " 2 - Shows all the people on the list of the chosen city\n"
<< " 3 - Writes all male information into a file called results.txt\n"
<< " 4 - Writes information of people of a chosen city & older than 30 to results.txt\n"
<< " 5 - Writes the last result in a file\n"
<< " 6 - Finish\n"
<<"\n"
<< "Please enter a number: ";
cin >> menu;
if(cin.fail()){
    cout<<"***Please enter a number***."<<endl;
     cin.clear();
     cin.ignore();
}
else{
switch (menu){
case 1:{
for (i=0;i<10;i++){
        if (arr[i].birthDate < maxNumber){
            maxNumber=arr[i].birthDate;
            j=i;
        }
    }
    emptySpace();
    cout<<"Answer: "<<endl;
    infoWithJ();
option=1;
break;
}

case 2:{
cout<<"Please enter the name of the city"<<endl;
    cin>>inputCity;
    for (i=0;i<10;i++){
    if (arr[i].city==inputCity){
    emptySpace();
    cout<<"Person #"<<personNumber<<":"<<endl;
    personNumber++;
    infoWithI();
        }
        else theEnd++;
    }
    if (theEnd >=10) cityError();
    theEnd=0;
option=2;
personNumber=1;
break;
}

case 3:{
 ofstream fout;
    fout.open("results.txt");
    for (i=0;i<10;i++){
    if (arr[i].gender=="Male"){
    fout<<arr[i].name<<" ";
    fout<<arr[i].lastName<<" ";
    fout<<arr[i].birthDate<<" ";
    fout<<arr[i].city<<" ";
    fout<<arr[i].gender<<" "<<endl;
    personNumber++;
        }
    }
    fout.close();
    emptySpace();
thisResult();
option=3;
break;
}

case 4:{
cout<<"Please enter the name of the city"<<endl;
    cin>>inputCity;
    ofstream fout;
    fout.open("results.txt");
    for (i=0;i<10;i++){
        if ((1987>arr[i].birthDate) && (arr[i].city==inputCity)){
    emptySpace();
    fout<<arr[i].name<<" ";
    fout<<arr[i].lastName<<" ";
    fout<<arr[i].birthDate<<" ";
    fout<<arr[i].city<<" ";
    fout<<arr[i].gender<<" "<<endl;
        }
        else theEnd2++;
    }
    if (theEnd2>=10){
cityError();
fout<<"***The city you entered is either:***\n   - Not from the list\n   - Written in lower case\n   - Has a typo\n";
fout<<"***Please enter the city from the list*** \n***with the first letter capitalized (example: London)***";

    }
    fout.close();
    emptySpace();
thisResult();
option=4;
break;
}

case 5:{
if (option==0){
emptySpace();
cout<<"***Please chose an option from 1, 2 ,3 or 4 first***."<<endl;
}
else if (option==1){
ofstream fout;
fout.open("results.txt");
    fout<<arr[j].name<<" ";
    fout<<arr[j].lastName<<" ";
    fout<<arr[j].birthDate<<" ";
    fout<<arr[j].city<<" ";
    fout<<arr[j].gender<<" "<<endl;
fout.close();
emptySpace();
thisResult();
}
else if (option==2){
ofstream fout;
fout.open("results.txt");
for (int i=0;i<10;i++){
    if (arr[i].city==inputCity){
    fout<<arr[i].name<<" ";
    fout<<arr[i].lastName<<" ";
    fout<<arr[i].birthDate<<" ";
    fout<<arr[i].city<<" ";
    fout<<arr[i].gender<<" "<<endl;
        }
    }
    if (theEnd >=10){
    fout<<"***The city you entered is either:***\n   - Not from the list\n   - Written in lower case\n   - Has a typo\n";
    fout<<"***Please enter the city from the list*** \n***with the first letter capitalized (example: London)***";
     }
 fout.close();
emptySpace();
thisResult();
}
else if (option==3 || option==4){
emptySpace();
cout<<"***The chosen option data has already been transferred to results.txt file***."<<endl;
}
break;
}

case 6:
cout << "Program stopped.\n";
break;

default:
cout << "Not a valid number. \n"
<< "Please chose a number between 1 and 6.\n";
break;
}
}
}
while (menu !=6);

return 0;
}

