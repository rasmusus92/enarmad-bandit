#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int belopp =0;
int bets =0;
int resultat =0;
int satsa (){
    cout<<"Nu ska du sattsa!! Du får sattsa hur mycket du själv vill!!! Bara du har nog med pengar"<<endl;
        cin>>bets;
        while (bets>belopp){
            cout<<"Du måste lära dig att läsa! Du satsade "<<bets<<" du har "<<belopp<<endl;
            cin>>bets;
    }
    belopp=belopp-bets;
    cout<<"Bra du kan läsa så du har satsat rätt. Du satsade "<<bets<<". Och har "<<belopp<<" kvar."<<endl;
    return belopp;
}
int spelPl () {
    int rader [3][3];
    for (int e=0; e<3; e++){
        for (int t=0; t<3; t++){
            rader[e][t]=rand()%3+1;
        }
    }
    if ((rader[0][0])==(rader[1][0])&&(rader[0][0])==([2][0])){
    resultat ++;
    }
    if ((rader[1][0])==(rader[1][1])&&(rader[1][0])==([1][2])){
    resultat ++;
    }
    if ((rader[2][0])==(rader[2][1])&&(rader[2][0])==([2][2])){
    resultat ++;
    }
    if ((rader[0][0])==(rader[0][1])&&(rader[0][0])==([0][2])){
    resultat ++;
    }
    if ((rader[0][1])==(rader[1][1])&&(rader[0][1])==([1][2])){
    resultat ++;
    }
    if ((rader[0][2])==(rader[1][2])&&(rader[0][2])==([2][2])){
    resultat ++;
    }
    if ((rader[0][0])==(rader[1][1])&&(rader[0][0])==([2][2])){
    resultat ++;
    }
    if ((rader[0][2])==(rader[1][1])&&(rader[0][2])==([2][0])){
    resultat ++;
    }
    for (int e=0; e<3; e++){
    for (int t=0; t<3; t++){
        if(rader[e][t] == 1){
           cout<<"[Z]";
        }
        if(rader[e][t] == 2){
           cout<<"[X]";
        }
        if(rader[e][t] == 3){
           cout<<"[C]";
        }
    }
    cout<<endl;
    }
    return rader[3][3];
}

int main () {
    srand(time(0));
    cout<<"Hej, Du ska sätta in pengar så du kan satsa och vinna cash!"<<endl<<"50, 100 eller 500 kr"<<endl;
    cout<<"Spel regler kommer under."<<endl;
    cout<<"En rad________________2 Gånger pengarna."<<endl;
    cout<<"Två rader_____________4 Gånger pengarna."<<endl;
    cout<<"Tre rader_____________8 Gånger pengarna."<<endl;
    cout<<"Fyra rader___________16 Gånger pengarna."<<endl;
    cout<<"Fullt spelfält______128 Gånger pengarna."<<endl;
    cout<<"Nu ska du sätta in pengar"<<endl;
    cin>>belopp;
    cout<<"Du satte in "<<belopp<<"!"<<endl;
    while ((belopp!=50)&&(belopp!=100)&&(belopp!=500)){
        cout<<"LoL, Du måste sätta in rätt dude... 50, 100 eller 500"<<endl;
        cin>>belopp;
        cout<<"Du satte in "<<belopp<<"!"<<endl;
    }
    cout<<"Du satte in rätt! Du satte in "<<belopp<<"!"<<endl;
    satsa();
    cout<<"Här kommer spelfältet! Lycka till"<<endl;
    spelPl();
    
return 0;
}
