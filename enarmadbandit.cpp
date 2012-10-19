#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int belopp =0;
int bets =0;
int resultat =0;
/*Den här funktionen tar hand om satsningen i spelet.*/
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
/*Den här funktionen tar hand om att skriva ut spelet och räkna ut resultatet*/
void spelPl () {
    resultat=0;
    int rader[3][3];
    for (int e=0; e<3; e++){
        for (int t=0; t<3; t++){
            rader[e][t]=rand()%3+1;
        }
    }
    if ((rader[0][0])==(rader[1][0])&&(rader[0][0])==(rader[2][0])){
        resultat ++;
    }
    if ((rader[1][0])==(rader[1][1])&&(rader[1][0])==(rader[1][2])){
        resultat ++;
    }
    if ((rader[2][0])==(rader[2][1])&&(rader[2][0])==(rader[2][2])){
        resultat ++;
    }
    if ((rader[0][0])==(rader[0][1])&&(rader[0][0])==(rader[0][2])){
        resultat ++;
    }
    if ((rader[0][1])==(rader[1][1])&&(rader[0][1])==(rader[2][1])){
        resultat ++;
    }
    if ((rader[0][2])==(rader[1][2])&&(rader[0][2])==(rader[2][2])){
        resultat ++;
    }
    if ((rader[0][0])==(rader[1][1])&&(rader[0][0])==(rader[2][2])){
        resultat ++;
    }
    if ((rader[0][2])==(rader[1][1])&&(rader[0][2])==(rader[2][0])){
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
}
/*Den här funktionen tar hand om att räkna ut hur mycket pengar man får ut*/
int vinster(int fbelopp, int fbet){
    if (resultat == 1){
        fbet=fbet*2;
        fbelopp+=fbet;
        cout<<"Du fick en rad :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 2){
        fbet=fbet*4;
        fbelopp+=fbet;
        cout<<"Du fick två rader :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 3){
        fbet=fbet*8;
        fbelopp+=fbet;
        cout<<"Du fick tre rader :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 4){
        fbet=fbet*16;
        fbelopp+=fbet;
        cout<<"Du fick fyra rader :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 5){
        fbet=fbet*32;
        fbelopp+=fbet;
        cout<<"Du fick fem rader :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 6){
        fbet=fbet*64;
        fbelopp+=fbet;
        cout<<"Du fick sex rader :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    if (resultat == 8){
        fbet=fbet*128;
        fbelopp+=fbet;
        cout<<"Du fick fullt spelfält :)"<<endl;
        cout<<"Du vann " <<fbet<<endl;
        belopp=belopp+fbet;
    }
    else if (resultat == 0){
    cout<<"Happ här blev det inget bättre lycka nästa gång."<<endl;
    }
    return fbelopp;
}


int main () {
    char spelom;
    srand(time(0));
    /*Intro till spelet*/
    cout<<"Hej, Du ska sätta in pengar så du kan satsa och vinna cash!"<<endl;
    cout<<"|-------Spel regler kommer under.--------|"<<endl;
    cout<<"|En rad________________2 Gånger pengarna.|"<<endl;
    cout<<"|Två rader_____________4 Gånger pengarna.|"<<endl;
    cout<<"|Tre rader_____________8 Gånger pengarna.|"<<endl;
    cout<<"|Fyra rader___________16 Gånger pengarna.|"<<endl;
    cout<<"|Fem rader____________32 Gånger pengarna.|"<<endl;
    cout<<"|Sex rader____________64 Gånger pengarna.|"<<endl;
    cout<<"|Fullt spelfält______128 Gånger pengarna.|"<<endl;
    cout<<"|_______Nu ska du sätta in pengar._______|"<<endl;
    /*Här startar spelet med att man sätter in pengar*/
    cout<<"50, 100 eller 500 kr"<<endl;
    cin>>belopp;
    cout<<"Du satte in "<<belopp<<"!"<<endl;
    while ((belopp!=50)&&(belopp!=100)&&(belopp!=500)){
        cout<<"LoL, Du måste sätta in rätt dude... 50, 100 eller 500"<<endl;
        cin>>belopp;
        cout<<"Du satte in "<<belopp<<"!"<<endl;
    }
    cout<<"Du satte in rätt! Du satte in "<<belopp<<"!"<<endl;
    /*Här är alla funktioner insatta in en loop som gör att man kan spela om spelet tills man har slut på pengar eller tröttnar.*/
    while (belopp!=0){
        satsa();
        cout<<"Här kommer spelfältet! Lycka till"<<endl;
        spelPl();
        belopp=vinster(belopp, bets);
        cout<<"Du har så här mycket pengar just nu "<<belopp<<endl;
        cout<<"Vill du ta ut pengarna eller vinna mer?!?! y för ja."<<endl;
        cin>>spelom;
        if ((spelom=='y')||(spelom=='Y')){
            cout<<"Du valde att ta ut pengarna. Du får "<<belopp<<endl;
            return 0;
        }
    }
    return 0;
    /*SLUT!*/
}
