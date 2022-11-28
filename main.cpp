#include<iostream>
#include<string.h>
using namespace std;
int main(){
    //char message[] = "BONJOUR";
    char message[90];
    cout<<"Entrer un message : ";
    cin>>message;
    //char cle[] = "FEU";
    char cle[26];
    cout<<"Definir une cle : ";
    cin>>cle;
    int taille_message = strlen(message), taille_cle = strlen(cle), i, j;
    char nouvelle_cle[taille_message], message_crypte[taille_message], message_decrypte[taille_message];
    //Générer une nouvelle clé
    for(i = 0, j = 0; i < taille_message; ++i, ++j){
        if(j == taille_cle)
            j = 0;
        nouvelle_cle[i] = cle[j];
    }
    nouvelle_cle[i] = '\0';
    //Cryptage
    for(i = 0; i < taille_message; ++i)
        message_crypte[i] = ((message[i] + nouvelle_cle[i]) % 26) + 'A';
    message_crypte[i] = '\0';
    //Décryptage
    for(i = 0; i < taille_message; ++i)
        message_decrypte[i] = (((message_crypte[i] - nouvelle_cle[i]) + 26) % 26) + 'A';
    message_decrypte[i] = '\0';
    cout<<"---------------SUBSTITION POLY-ALPHABETIQUE---------------";
    cout<<"\n                    Texte en clair: "<<message;
    cout<<"\n                         Cle: "<<cle;
    //cout<<"\nNouvelle cle genere: "<<nouvelle_cle;
    cout<<"\n                    Texte chiffre: "<<message_crypte;
    //cout<<"\nTexte en clair: "<<message_decrypte<<endl;
    cout<<"\n----------------------------FIN---------------------------"<<endl;
    return 0;
}
