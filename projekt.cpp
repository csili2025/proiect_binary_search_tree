#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"
#include <algorithm>

#include <windows.h>

using namespace std;

int main()
{   
    int level;
    BinarySearchTree bst;
    bool kilepes = true;
    bool szintek = true;
 

    system("Color C");
    while (szintek) 
    {
        system("CLS");
        cout << "                               Akasztofa" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "A jatek elkezdesehez szukseges elobb szintet valasztania:" << endl;
        cout << "Konnyu - 1" << endl;
        cout << "Kozepes - 2" << endl;
        cout << "Nehez - 3" << endl;
        cin >> level;

        if (level == 1)
        {
            bst.buildTreeFromFile("szavak1.txt");
            szintek = false;

        }
        else if (level == 2)
        {
            bst.buildTreeFromFile("szavak2.txt");
            szintek = false;
        }
        else if (level == 3)
        {
            bst.buildTreeFromFile("szavak3.txt");
            szintek = false;
        }
        else
        {
            cout << "Hibas szam!";
            Sleep(700);
        }
    }

    while (kilepes)
    {
        system("CLS");
        cout << "                               Akasztofa" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "0. Kilepni a jatekbol." << endl;
        cout << "1. Jatek inditasa." << endl;
        cout << "2. Szabalyzat." << endl;
        cout << "3. Torolni egy szot a jatekbol" << endl;
        cout << "4. Betenni egy uj szot." << endl;
        cout << "5. Szintcsere" << endl;

        string newWord;
        string torol;
        int parancs;

        cin >> parancs;

        switch (parancs)
        {
        case 0:
            system("CLS");
            cout << "Vege kileptel!" << endl;
            kilepes = false;
            break;
        case 1:
            cout << "Jatek inditasa!" << endl;
            bst.jatekpanel();
            cout << endl;
            break;
        case 2:
            system("CLS");
            cout << "Szabalyzat:" << endl << endl;
            cout << "1. A jatek elejan 7 eleted van." << endl;
            cout << "2. A jatek random general egy szot attol fuggoen, hogy a 3 szint kozul melyiket valasztottad : konnyu, kozepes, vagy nehez." << endl;
            cout << "3. A celod kitalalni a szo betuit." << endl;
            cout << "4. Tippelhetsz betuket egyenkent, vagy a 'help' paranccsal kerheted az elso betut, de ez 1 eletbe kerul." << endl;
            cout << "5. A 'tipp' paranccsal probalkozhatsz egy szoval. Ha eltalaltad, nyertel. Ha a szo benne van a szotarban, kapsz egy plusz eletet. Ha nincs benne, akkor 2 eletet veszitesz." << endl;
            cout << "6. Minden korben egy betut tippelhetsz." << endl;
            cout << "7. Csalas tilos." << endl << endl;
            system("pause");
            break;
        case 3:
            cout << "Torolendo szo:" << endl;
            cin >> torol;
            cout << endl;
            bst.deleteWord(torol);
            break;
        case 4:
            cout << "Kerem adjon meg egy uj szot: ";
            cin >> newWord;
            bst.insertWord(newWord);
            break;
        case 5:
            system("CLS");
            cout << "                               Akasztofa" << endl;
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Szintcsere:\n";
            cout << "Konnyu  - 1" << endl;
            cout << "Kozepes - 2" << endl;
            cout << "Nehez   - 3" << endl;
           
            cin >> level;
           
                if (level == 1)
                { 
                    bst.BinarySearchTreeDelet();
                    bst.buildTreeFromFile("szavak1.txt");
                }
                else if (level == 2)
                { 
                    bst.BinarySearchTreeDelet();
                    bst.buildTreeFromFile("szavak2.txt");
                  
                }
                else if (level == 3)
                {
                    bst.BinarySearchTreeDelet();
                    bst.buildTreeFromFile("szavak3.txt");
                }
            
        
        default:
       
            break;
        }
    }
 
    cout << "Szeretned kiiratni a konyvtarat?" << endl;
    string valasz;
    cin >> valasz;
    if (valasz == "igen")
    {
        cout << "InOrder - 0" << endl;
        cout << "PostOrder - 1" << endl;
        int szam;
        cin >> szam;
        if (szam == 0)
        {
            bst.printTree();
        }
        else 
        {
            bst.printTree2();
        }
    }
 

   
    return 0;
}
