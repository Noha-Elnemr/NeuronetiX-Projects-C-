#include <iostream>
using namespace std;

struct pet
{
    string petsname;
    int fulllevel = 50;
    int happinesslevel = 50;
    bool adopted = false;
};
pet petto;

struct pet adopt(pet &petto)
{
    petto.fulllevel = 50;
    petto.happinesslevel = 50;
    while (!petto.adopted)
    {
        cout << "enter your pets name: " << endl;
        cin >> petto.petsname;
        if (!petto.petsname.empty())
        {
            cout << petto.petsname << " has been adopted. " << endl;
            petto.adopted = true;
        }
    }
    return petto;
}

struct pet feed(pet &petto)
{
    if (petto.fulllevel < 90)
    {
        petto.fulllevel += 10;
        petto.happinesslevel -= 10;
        cout << petto.petsname << " has been fed." << endl;
    }

    if (petto.fulllevel == 90)
    {
        cout << petto.petsname << " is full." << endl;
    }

    return petto;
}

struct pet play(pet &petto)
{

    if (petto.happinesslevel < 90)
    {
        petto.happinesslevel += 10;
        petto.fulllevel -= 20;
        cout << petto.petsname << " played and is happier now." << endl;
    }

    if (petto.happinesslevel == 90)
    {
        cout << petto.petsname << " is satisfied." << endl;
    }

    return petto;
}

void checkstatus(pet &petto)
{

    cout << petto.petsname << " hunger level: " << petto.fulllevel << endl;
    cout << petto.petsname << " happiness level: " << petto.happinesslevel << endl;
}

void endgame(pet &petto)
{

    if (petto.adopted)
    {
        cout << petto.petsname << " hunger level: " << petto.fulllevel << endl;
        cout << petto.petsname << " happiness level: " << petto.happinesslevel << endl;
    }

    cout << "game over" << endl;
    exit(1);
}

void menu()
{

    pet petto;

    do
    {
        cout << "1. adopt pet " << endl;
        cout << "2. feed pet " << endl;
        cout << "3. play with pet " << endl;
        cout << "4. check status " << endl;
        cout << "5. end game " << endl;
        cout << "choose an option: " << endl;

        int choicenumber;
        cin >> choicenumber;

        if (choicenumber == 1)
        {
            adopt(petto);
        }
        else if (choicenumber == 5)
        {
            endgame(petto);
        }

        if (petto.adopted)
        {
            switch (choicenumber)
            {

            case 2:
                petto = feed(petto);
                break;

            case 3:
                petto = play(petto);
                break;

            case 4:
                checkstatus(petto);
                break;

            case 5:
                endgame(petto);
                break;
            }
        }
        else
        {
            cout << "you havent adopted a pet. " << endl;
        }
    } while (petto.happinesslevel > 0 && petto.fulllevel > 0);

    if (petto.happinesslevel <= 0 || petto.fulllevel <= 0)
    {
        cout << " game over. your pet's condition has reached critical levels." << endl;
    }
}

int main()
{

    menu();

    return 0;
}
