#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int belopp;
int bets;

int satsa ()
{
    cout<<"Nu ska du satsa!! Du får sattsa hur mycket du själv vill!!! Bara du har nog med pengar"<<endl;
    if (cin>>bets) // Avoid non-integer failure
    {
        while (bets>belopp || bets < 1){
            cout<<"Du måste lära dig att läsa! Du satsade "<<bets<<" du har "<<belopp<<endl;
            cin>>bets;
        }
        belopp = belopp - bets;
        cout<<"Bra du kan läsa så du har satsat rätt. Du satsade "<<bets<<". Och har "<<belopp<<" kvar."<<endl;
        return belopp;
    } else {
        cout << "Det där är inte ens en siffra. Försök igen.";
        return 0;
    }

}
int spelPl ()
{
    int resultat = 0;
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
            resultat++;
        }

        if((rader[j][0]) == (rader[j][1]) && (rader[j][0]) == (rader[j][2]))
        // Check horizontal matches
        {
            resultat++;
        }

        // TODO: Diagonal?
        if(j != 1)
        {
            if((rader[0][j]) == rader[1][1] &&
                rader[0][j] == rader[2][(j+2) % 4]) // Quick and Dirty
            {
                resultat++;
            }
        }
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

    if (resultat == 1)
    {
        return 2;
    }
    else if (resultat == 2)
    {
        return 4;
    }
    else if (resultat == 3)
    {
        return 8;
    }
    else if (resultat == 4)
    {
        return 16;
    }
    else if (resultat > 4)
    {
        return 128;
    }
    else
    {
        return 0;
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
        while (belopp > 0)
        {
            satsa();
            cout<<"Här kommer spelfältet! Lycka till"<<endl;
            belopp += bets * spelPl();
            cout << "Resultat:" << belopp << endl;
        }
    } else {
        cout << "Hur tänkte du nu? Det där är inte ens en siffra";
        return -1;
    }


    return 0;
}
