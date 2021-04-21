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

mas[10];
int i, j, k=1;

void infoWithI(){
    cout<<mas[i].name<<" ";
    cout<<mas[i].lastName<<" ";
    cout<<mas[i].birthDate<<" ";
    cout<<mas[i].city<<" ";
    cout<<mas[i].gender<<" "<<endl;
}

void infoWithJ(){
    cout<<mas[j].name<<" ";
    cout<<mas[j].lastName<<" ";
    cout<<mas[j].birthDate<<" ";
    cout<<mas[j].city<<" ";
    cout<<mas[j].gender<<" "<<endl;
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
int menu, option=0, x=99999;
string inputCity;

ifstream fin;

fin.open("residents.txt");
for (i=0;i<10;i++){
    fin>>mas[i].name;
    fin>>mas[i].lastName;
    fin>>mas[i].birthDate;
    fin>>mas[i].city;
    fin>>mas[i].gender;
}
fin.close();

for (i=0;i<10;i++){
    infoWithI();
}

do{
cout << endl
<< " 1 - Shows the oldest person on the list.\n"
<< " 2 - Shows all the people on the list of the chosen city\n"
<< " 3 - Puts all male information into a file called results.txt\n"
<< " 4 - Puts information of people of a chosen city & older than 30 to results.txt\n"
<< " 5 - Puts the last result in a file\n"
<< " 6 - Finish\n"
<<"\n"
<< "Please enter a number: ";
cin >> menu;

switch (menu){
case 1:{
for (i=0;i<10;i++){
        if (mas[i].birthDate < x){
            x=mas[i].birthDate;
            j=i;
        }
    }
    emptySpace();
    cout<<"Answer: "<<endl;
    infoWithJ();
option=1;
break;}

case 2:{
cout<<"Please enter the name of the city"<<endl;
    cin>>inputCity;
    for (i=0;i<10;i++){
    if (mas[i].city ==inputCity){
    emptySpace();
    cout<<"Person #"<<k<<":"<<endl;
    k++;
    infoWithI();
        }
         else{
            cityError();
            break;
        }
    }

option=2;
k=1;
break;}

case 3:{
 ofstream fout;
    fout.open("results.txt");
    for (i=0;i<10;i++){
    if (mas[i].gender=="Male"){
    fout<<mas[i].name<<" ";
    fout<<mas[i].lastName<<" ";
    fout<<mas[i].birthDate<<" ";
    fout<<mas[i].city<<" ";
    fout<<mas[i].gender<<" "<<endl;
    k++;
        }
    }
    fout.close();
    emptySpace();
thisResult();
option=3;
break;}

case 4:{
cout<<"Please enter the name of the city"<<endl;
    cin>>inputCity;
    ofstream fout;
    fout.open("results.txt");
    for (i=0;i<10;i++){
        if ((1987>mas[i].birthDate) && (mas[i].city==inputCity)){
    emptySpace();
    fout<<mas[i].name<<" ";
    fout<<mas[i].lastName<<" ";
    fout<<mas[i].birthDate<<" ";
    fout<<mas[i].city<<" ";
    fout<<mas[i].gender<<" "<<endl;
        }
    else{
        cityError();
        break;
    }
    }
    fout.close();
    emptySpace();
thisResult();
option=4;

break;}

case 5:{
if (option==0){
emptySpace();
cout<<"***Please chose an option from 1, 2 ,3 or 4 first***."<<endl;
}
else if (option==1){
ofstream fout;
fout.open("results.txt");
    fout<<mas[j].name<<" ";
    fout<<mas[j].lastName<<" ";
    fout<<mas[j].birthDate<<" ";
    fout<<mas[j].city<<" ";
    fout<<mas[j].gender<<" "<<endl;
fout.close();
emptySpace();
thisResult();
}
else if (option==2){
ofstream fout;
fout.open("results.txt");
for (int i=0;i<10;i++){
    if (mas[i].city==inputCity){
    fout<<mas[i].name<<" ";
    fout<<mas[i].lastName<<" ";
    fout<<mas[i].birthDate<<" ";
    fout<<mas[i].city<<" ";
    fout<<mas[i].gender<<" "<<endl;
        }
    }
fout.close();
emptySpace();
thisResult();
}
else if (option==3 || option==4){
emptySpace();
cout<<"***The chosen option data has already been transferred to results.txt file***."<<endl;
}
break;}

case 6:
cout << "Program stopped.\n";
break;

default:
cout << "Not a valid number. \n"
<< "Please chose a number between 1 and 6.\n";
break;
}
}while (menu !=6);
return 0;
}
