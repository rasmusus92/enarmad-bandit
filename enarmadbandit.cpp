#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int belopp;
int bets;
int resultat;

int satsa ()
{
    cout<<"Nu ska du satsa!! Du får sattsa hur mycket du själv vill!!! Bara du har nog med pengar"<<endl;
    if (cin>>bets) // Avoid non-integer failure
    {
        while (bets>belopp){
            cout<<"Du måste lära dig att läsa! Du satsade "<<bets<<" du har "<<belopp<<endl;
            cin>>bets;
            belopp=belopp-bets;
            cout<<"Bra du kan läsa så du har satsat rätt. Du satsade "<<bets<<". Och har "<<belopp<<" kvar."<<endl;
            return belopp;
        }
    } else {
        cout << "Det där är inte ens en siffra. Försök igen.";
        return 0;
    }

}
void spelPl ()
{
    int rader[3][3];
    for (int e=0; e<3; e++){
        for (int t=0; t<3; t++){
            rader[e][t]=rand()%3+1;
        }
    }

    for (int j=0; j<3; j++)
    {
        if((rader[0][j]) == (rader[1][j]) && (rader[0][j]) == (rader[2][j]))
        // Check vertical matches
        {
            cout << "Vertical\n";
            resultat++;
        }

        if((rader[j][0]) == (rader[j][1]) && (rader[j][0]) == (rader[j][2]))
        // Check horizontal matches
        {
            cout << "Horizontal\n";
            resultat++;
        }

        // TODO: Diagonal?
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

    if (cin >> belopp) // Avoid non-int failure
    {
        while ((belopp!=50)&&(belopp!=100)&&(belopp!=500)){
            cout<<"LoL, Du måste sätta in rätt dude... 50, 100 eller 500"<<endl;
            cin>>belopp;
            cout<<"Du satte in "<<belopp<<"!"<<endl;
        }
        cout<<"Du satte in rätt! Du satte in "<<belopp<<"!"<<endl;
        satsa();
        cout<<"Här kommer spelfältet! Lycka till"<<endl;
        spelPl();
    } else {
        cout << "Hur tänkte du nu? Det där är inte ens en siffra";
        return -1;
    }


    return 0;
}
