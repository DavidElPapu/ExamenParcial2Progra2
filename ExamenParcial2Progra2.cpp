
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void showInventory(vector<string> inventory, unsigned int freeSpaceLimit);

int main()
{
    //Este es para el limite total
    const unsigned int spaceLimit = 15;
    //Este es para el limite de espacios gratis para el jugador
    unsigned int freeSpaceLimit = 6;
    vector<string> inventory(spaceLimit, "(Espacio Disponible)");
    //Estos son los objetos, puede añadirle o quitarle si quiere
    vector<string> objects =
    {
        "Palo",
        "Hielera",
        "Zapato",
        "Reloj",
        "Gorra",
        "Lata",
        "Sombrero",
        "Caja",
        "Telefono",
        "Hoja",
        "Palanca",
        "Lupa",
        "Cinta",
        "Martillo",
        "Moneda",
        "Antorcha",
        "Piedra",
        "Canasta",
        "Cubeta",
        "Puerta"
    };
    //vector<string>::const_iterator iter; (no encontre un buen lugar para usarlo, ya que el i normal me servia mejor para enumerar cosas y relacionarlo con otros vectores)
    string ok;
    int option = 0;
    //Estas son las gemas, puede disminur el numero por si quiere ver que pasa cuando se acaban
    int gemas = 100;
    for (int i = 0; i < objects.size(); i++)
    {
        system("cls");
        
        if (inventory[freeSpaceLimit - 1] != "(Espacio Disponible)")
        {
            option = 0;
            while (option <= 0 || option > 3)
            {
                system("cls");
                showInventory(inventory, freeSpaceLimit);
                cout << "Has recibido un " << objects[i] << ", pero no te queda espacio" << endl;
                cout << "Que desea hacer?" << endl;
                cout << "1) Reemplazar un objeto por la " << objects[i] << endl;
                cout << "2) Continuar sin la " << objects[i] << endl;
                cout << "3) Añadir un espacio por 5 gemas, (tienes " << gemas << " gemas)" << endl;
                cin >> option;
            }
            switch (option)
            {
            case 1:
                option = 0;
                while (option <= 0 || option > freeSpaceLimit)
                {
                    system("cls");
                    showInventory(inventory, freeSpaceLimit);
                    cout << "Escriba el numero del objeto que desea cambiar" << endl;
                    cin >> option;
                }
                inventory[option - 1] = objects[i];
                break;
            case 2:
                cout << "Has ignorado la " << objects[i] << endl;
                cout << "(escribe cualquier cosa para continuar)" << endl;
                cin >> ok;
                break;
            case 3:
                freeSpaceLimit += 1;
                gemas -= 5;
                if (gemas < 0)
                {
                    option = 0;
                    while (option <= 0 || option > 2)
                    {
                        system("cls");
                        cout << "Ya no tienes gemas" << endl;
                        cout << "Que desea hacer entonces?" << endl;
                        cout << "1) Reemplazar un objeto por la " << objects[i] << endl;
                        cout << "2) Continuar sin la " << objects[i] << endl;
                        cin >> option;
                    }
                    if (option == 1)
                    {
                        option = 0;
                        while (option <= 0 || option > freeSpaceLimit)
                        {
                            system("cls");
                            showInventory(inventory, freeSpaceLimit);
                            cout << "Escriba el numero del objeto que desea cambiar" << endl;
                            cin >> option;
                        }
                        inventory[option - 1] = objects[i];
                    }
                    else
                    {
                        cout << "Has ignorado la " << objects[i] << endl;
                        cout << "(escribe cualquier cosa para continuar)" << endl;
                        cin >> ok;
                    }
                }
                else
                {
                    if (freeSpaceLimit > spaceLimit)
                    {
                        freeSpaceLimit -= 1;
                        gemas += 5;
                        option = 0;
                        while (option <= 0 || option > 2)
                        {
                            system("cls");
                            cout << "Alcanzaste el limite de espacios disponibles" << endl;
                            cout << "Que desea hacer entonces?" << endl;
                            cout << "1) Reemplazar un objeto por la " << objects[i] << endl;
                            cout << "2) Continuar sin la " << objects[i] << endl;
                            cin >> option;
                        }
                        if (option == 1)
                        {
                            option = 0;
                            while (option <= 0 || option > freeSpaceLimit)
                            {
                                system("cls");
                                showInventory(inventory, freeSpaceLimit);
                                cout << "Escriba el numero del objeto que desea cambiar" << endl;
                                cin >> option;
                            }
                            inventory[option - 1] = objects[i];
                        }
                        else
                        {
                            cout << "Has ignorado la " << objects[i] << endl;
                            cout << "(escribe cualquier cosa para continuar)" << endl;
                            cin >> ok;
                        }
                    }
                    else
                    {
                        inventory[freeSpaceLimit - 1] = objects[i];
                    }
                }
                break;
            }
            
        }
        else
        {
            inventory[i] = objects[i];
            showInventory(inventory, freeSpaceLimit);
            cout << "Has recibido un " << objects[i] << endl;
            cout << "(escribe cualquier cosa para continuar)" << endl;
            cin >> ok;
        } 
    }
    system("cls");
    cout << "Se acabaron los objetos!" << endl;
    showInventory(inventory, freeSpaceLimit);
}

void showInventory(vector<string> inventory, unsigned int freeSpaceLimit)
{
    cout << "Inventario:" << endl;
    for (int i = 0; i < freeSpaceLimit; i++)
    {
        cout << i + 1 << ") " << inventory[i] << endl;
    }
}


