#include <iostream>
#include <vector>
#include <thread> // se pude introducir retraso en la ejecución de un hilo
#include <chrono> // trabajar con milisegundos
using namespace std;

class Celula
{
protected:
    bool estado = 0;

public:
    Celula() {}
    Celula(bool);
    void ModificarVida(bool);
    bool getEstado();
};

Celula::Celula(bool e) : estado(e) {}

void Celula::ModificarVida(bool e) { estado = e; }

bool Celula::getEstado() { return estado; }

class Matriz
{
protected:
    vector<vector<Celula>> matriz;

public:
    Matriz();
    void CambiarCelula(int, int);

    Celula getCelulaPos(int, int);

    void MostrarMatriz();

    bool Limite2(int, int);

    void ProximoEstado();

    void LimpiarMatriz();
};

Matriz::Matriz()
{
    vector<vector<Celula>> espacio;
    for (int i = 0; i < 30; i++)
    {
        vector<Celula> v(50);
        espacio.push_back(v);
    }
    matriz = espacio;
}

Celula Matriz ::getCelulaPos(int x, int y) { return matriz[x][y]; }

void Matriz::CambiarCelula(int x, int y) { matriz[x][y].ModificarVida(true); }

void Matriz::MostrarMatriz()
{
    cout << "   ";
    for (int i = 0; i < matriz[0].size(); i++)
    {
        if (i < 10)
        {
            cout << i << "  ";
        }
        else
        {
            cout << i << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < matriz.size(); i++)
    {
        if (i < 10)
        {
            cout << i << "  ";
        }
        else
        {
            cout << i << " ";
        }
        for (int j = 0; j < matriz[i].size(); j++)
        {
            if (matriz[i][j].getEstado())
                cout << "#  ";
            else
                cout << ".  ";
        }
        cout << endl;
    }
}

bool Matriz::Limite2(int x, int y)
{
    if ((x >= 0 && x < matriz.size()) && (y >= 0 && y < matriz[0].size()))
        return true;
    return false;
}

void Matriz::ProximoEstado()
{
    vector<vector<Celula>> v2 = matriz;
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[i].size(); j++)
        {
            int c_vivos = 0, c_muertos = 0;
            for (int l = -1; l <= 1; l++)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (l == 0 && k == 0)
                    {
                        continue;
                    }
                    else
                    {
                        if (Limite2(i + l, j + k))
                        {
                            if (matriz[i + l][j + k].getEstado())
                                c_vivos++;
                            else
                                c_muertos++;
                        }
                    }
                }
            }
            if (matriz[i][j].getEstado() == 1)
            {
                if (c_vivos == 2 || c_vivos == 3)
                    v2[i][j].ModificarVida(1);
                else
                    v2[i][j].ModificarVida(0);
            }
            else
            {
                if (c_vivos == 3)
                    v2[i][j].ModificarVida(1);
            }
        }
    }
    matriz = v2;
}

void Matriz::LimpiarMatriz()
{
    for (int i = 0; i < matriz.size(); i++)
        for (int j = 0; j < matriz[i].size(); j++)
            matriz[i][j].ModificarVida(false);
}

class tipoCelula : public Celula, public Matriz
{
public:
    void oscilador_blinker(int x, int y);

    void oscilador_beacom(int x, int y);

    void oscilador_pulsar(int x, int y);

    void oscilador_Penta_Decathlon(int x, int y);

    void NaveEspacial_Glinder(int x, int y);

    void NaveEspacial_Light_Weight_Spaceship(int x, int y);

    void Canon_Gosper_Glider_Gun(int x, int y);
};

void tipoCelula ::oscilador_beacom(int x, int y)
{
    matriz[x][y].ModificarVida(true);
    matriz[x + 1][y].ModificarVida(true);
    matriz[x][y + 1].ModificarVida(true);
    matriz[x + 2][y + 3].ModificarVida(true);
    matriz[x + 3][y + 3].ModificarVida(true);
    matriz[x + 3][y + 2].ModificarVida(true);
}

void tipoCelula ::oscilador_blinker(int x, int y)
{
    matriz[x][y].ModificarVida(true);
    matriz[x][y + 1].ModificarVida(true);
    matriz[x][y + 2].ModificarVida(true);
}

void tipoCelula ::oscilador_pulsar(int x, int y)
{
    matriz[x][y + 4].ModificarVida(true);
    matriz[x][y + 10].ModificarVida(true);
    matriz[x + 1][y + 4].ModificarVida(true);
    matriz[x + 1][y + 10].ModificarVida(true);
    matriz[x + 2][y + 4].ModificarVida(true);
    matriz[x + 2][y + 10].ModificarVida(true);
    matriz[x + 2][y + 5].ModificarVida(true);
    matriz[x + 2][y + 9].ModificarVida(true);
    matriz[x + 4][y].ModificarVida(true);
    matriz[x + 4][y + 1].ModificarVida(true);
    matriz[x + 4][y + 2].ModificarVida(true);
    matriz[x + 4][y + 5].ModificarVida(true);
    matriz[x + 4][y + 6].ModificarVida(true);
    matriz[x + 4][y + 8].ModificarVida(true);
    matriz[x + 4][y + 9].ModificarVida(true);
    matriz[x + 4][y + 12].ModificarVida(true);
    matriz[x + 4][y + 13].ModificarVida(true);
    matriz[x + 4][y + 14].ModificarVida(true);
    matriz[x + 5][y + 2].ModificarVida(true);
    matriz[x + 5][y + 4].ModificarVida(true);
    matriz[x + 5][y + 6].ModificarVida(true);
    matriz[x + 5][y + 8].ModificarVida(true);
    matriz[x + 5][y + 10].ModificarVida(true);
    matriz[x + 5][y + 12].ModificarVida(true);
    matriz[x + 6][y + 4].ModificarVida(true);
    matriz[x + 6][y + 5].ModificarVida(true);
    matriz[x + 6][y + 9].ModificarVida(true);
    matriz[x + 6][y + 10].ModificarVida(true);
    matriz[x + 8][y + 4].ModificarVida(true);
    matriz[x + 8][y + 5].ModificarVida(true);
    matriz[x + 8][y + 9].ModificarVida(true);
    matriz[x + 8][y + 10].ModificarVida(true);
    matriz[x + 9][y + 2].ModificarVida(true);
    matriz[x + 9][y + 4].ModificarVida(true);
    matriz[x + 9][y + 6].ModificarVida(true);
    matriz[x + 9][y + 8].ModificarVida(true);
    matriz[x + 9][y + 10].ModificarVida(true);
    matriz[x + 9][y + 12].ModificarVida(true);
    matriz[x + 10][y].ModificarVida(true);
    matriz[x + 10][y + 1].ModificarVida(true);
    matriz[x + 10][y + 2].ModificarVida(true);
    matriz[x + 10][y + 5].ModificarVida(true);
    matriz[x + 10][y + 6].ModificarVida(true);
    matriz[x + 10][y + 8].ModificarVida(true);
    matriz[x + 10][y + 9].ModificarVida(true);
    matriz[x + 10][y + 12].ModificarVida(true);
    matriz[x + 10][y + 13].ModificarVida(true);
    matriz[x + 10][y + 14].ModificarVida(true);
    matriz[x + 12][y + 4].ModificarVida(true);
    matriz[x + 12][y + 10].ModificarVida(true);
    matriz[x + 12][y + 5].ModificarVida(true);
    matriz[x + 12][y + 9].ModificarVida(true);
    matriz[x + 13][y + 4].ModificarVida(true);
    matriz[x + 13][y + 10].ModificarVida(true);
    matriz[x + 14][y + 4].ModificarVida(true);
    matriz[x + 14][y + 10].ModificarVida(true);
}

void tipoCelula ::oscilador_Penta_Decathlon(int x, int y)
{
    matriz[x][y].ModificarVida(true);
    matriz[x][y + 1].ModificarVida(true);
    matriz[x][y + 3].ModificarVida(true);
    matriz[x][y + 4].ModificarVida(true);
    matriz[x][y + 5].ModificarVida(true);
    matriz[x][y + 6].ModificarVida(true);
    matriz[x][y + 8].ModificarVida(true);
    matriz[x][y + 9].ModificarVida(true);
    matriz[x + 1][y + 2].ModificarVida(true);
    matriz[x + 1][y + 7].ModificarVida(true);
    matriz[x - 1][y + 2].ModificarVida(true);
    matriz[x - 1][y + 7].ModificarVida(true);
}

void tipoCelula ::NaveEspacial_Glinder(int x, int y)
{
    matriz[x][y].ModificarVida(true);
    matriz[x + 1][y + 1].ModificarVida(true);
    matriz[x + 1][y + 2].ModificarVida(true);
    matriz[x][y + 2].ModificarVida(true);
    matriz[x - 1][y + 2].ModificarVida(true);
}

void tipoCelula ::NaveEspacial_Light_Weight_Spaceship(int x, int y)
{
    matriz[x][y].ModificarVida(true);
    matriz[x][y + 1].ModificarVida(true);
    matriz[x + 1][y - 1].ModificarVida(true);
    matriz[x + 1][y].ModificarVida(true);
    matriz[x + 1][y + 1].ModificarVida(true);
    matriz[x + 1][y + 2].ModificarVida(true);
    matriz[x + 2][y - 1].ModificarVida(true);
    matriz[x + 2][y].ModificarVida(true);
    matriz[x + 2][y + 2].ModificarVida(true);
    matriz[x + 2][y + 3].ModificarVida(true);
    matriz[x + 3][y + 1].ModificarVida(true);
    matriz[x + 3][y + 2].ModificarVida(true);
}

void tipoCelula ::Canon_Gosper_Glider_Gun(int x, int y)
{
    matriz[x][y + 24].ModificarVida(true);
    matriz[x + 1][y + 24].ModificarVida(true);
    matriz[x + 1][y + 22].ModificarVida(true);
    matriz[x + 2][y + 21].ModificarVida(true);
    matriz[x + 2][y + 20].ModificarVida(true);
    matriz[x + 2][y + 13].ModificarVida(true);
    matriz[x + 2][y + 12].ModificarVida(true);
    matriz[x + 2][y + 34].ModificarVida(true);
    matriz[x + 2][y + 35].ModificarVida(true);
    matriz[x + 3][y + 21].ModificarVida(true);
    matriz[x + 3][y + 20].ModificarVida(true);
    matriz[x + 3][y + 34].ModificarVida(true);
    matriz[x + 3][y + 35].ModificarVida(true);
    matriz[x + 3][y + 15].ModificarVida(true);
    matriz[x + 3][y + 11].ModificarVida(true);
    matriz[x + 4][y].ModificarVida(true);
    matriz[x + 4][y + 1].ModificarVida(true);
    matriz[x + 4][y + 10].ModificarVida(true);
    matriz[x + 4][y + 16].ModificarVida(true);
    matriz[x + 4][y + 21].ModificarVida(true);
    matriz[x + 4][y + 20].ModificarVida(true);
    matriz[x + 5][y].ModificarVida(true);
    matriz[x + 5][y + 1].ModificarVida(true);
    matriz[x + 5][y + 10].ModificarVida(true);
    matriz[x + 5][y + 14].ModificarVida(true);
    matriz[x + 5][y + 16].ModificarVida(true);
    matriz[x + 5][y + 17].ModificarVida(true);
    matriz[x + 5][y + 22].ModificarVida(true);
    matriz[x + 5][y + 24].ModificarVida(true);
    matriz[x + 6][y + 10].ModificarVida(true);
    matriz[x + 6][y + 16].ModificarVida(true);
    matriz[x + 6][y + 24].ModificarVida(true);
    matriz[x + 7][y + 11].ModificarVida(true);
    matriz[x + 7][y + 15].ModificarVida(true);
    matriz[x + 8][y + 12].ModificarVida(true);
    matriz[x + 8][y + 13].ModificarVida(true);
}

void dormir(int x)
{
    this_thread::sleep_for(chrono::milliseconds(x));
}

void VectorParticulas(tipoCelula *m)
{
    int opcion;
    do
    {
        cout << " " << endl;
        cout << "----- OSCILADORES ----- NAVES ESPACIALES ----- CANONES -------" << endl;
        cout << "1. Blinker        5. Glider              7. Gosper Glider Gun" << endl;
        cout << "2. Beacon         6. Light-Weight" << endl;
        cout << "3. Pulsar" << endl;
        cout << "4. Decathlon" << endl;
        cout << " " << endl;
        cout << "0. Salir" << endl;
        cout << ">>";
        cin >> opcion;
        if (opcion == 1)
        {
            system("cls");
            m->LimpiarMatriz();
            m->oscilador_blinker(14, 22);
            m->MostrarMatriz();
        }
        else if (opcion == 2)
        {
            system("cls");
            m->LimpiarMatriz();
            m->oscilador_beacom(12, 18);
            m->MostrarMatriz();
        }
        else if (opcion == 3)
        {
            system("cls");
            m->LimpiarMatriz();
            m->oscilador_pulsar(7, 17);
            m->MostrarMatriz();
        }
        else if (opcion == 4)
        {
            system("cls");
            m->LimpiarMatriz();
            m->oscilador_Penta_Decathlon(14, 19);
            m->MostrarMatriz();
        }
        else if (opcion == 5)
        {
            system("cls");
            m->LimpiarMatriz();
            m->NaveEspacial_Glinder(4, 4);
            m->MostrarMatriz();
        }
        else if (opcion == 6)
        {
            system("cls");
            m->LimpiarMatriz();
            m->NaveEspacial_Light_Weight_Spaceship(13, 7);
            m->MostrarMatriz();
        }
        else if (opcion == 7)
        {
            system("cls");
            m->LimpiarMatriz();
            m->Canon_Gosper_Glider_Gun(6, 7);
            m->MostrarMatriz();
        }

    } while (opcion != 0);
    system("cls");
    m->MostrarMatriz();
};

void ASCCIjuegovida()
{
    cout << R"(
     _____  __    __  ________   ______    ______         _______   ________        __         ______         __     __  ______  _______    ______  
    /     |/  |  /  |/        | /      \  /      \       /       \ /        |      /  |       /      \       /  |   /  |/      |/       \  /      \ 
    $$$$$ |$$ |  $$ |$$$$$$$$/ /$$$$$$  |/$$$$$$  |      $$$$$$$  |$$$$$$$$/       $$ |      /$$$$$$  |      $$ |   $$ |$$$$$$/ $$$$$$$  |/$$$$$$  |
       $$ |$$ |  $$ |$$ |__    $$ | _$$/ $$ |  $$ |      $$ |  $$ |$$ |__          $$ |      $$ |__$$ |      $$ |   $$ |  $$ |  $$ |  $$ |$$ |__$$ |
  __   $$ |$$ |  $$ |$$    |   $$ |/    |$$ |  $$ |      $$ |  $$ |$$    |         $$ |      $$    $$ |      $$  \ /$$/   $$ |  $$ |  $$ |$$    $$ |
 /  |  $$ |$$ |  $$ |$$$$$/    $$ |$$$$ |$$ |  $$ |      $$ |  $$ |$$$$$/          $$ |      $$$$$$$$ |       $$  /$$/    $$ |  $$ |  $$ |$$$$$$$$ |
 $$ \__$$ |$$ \__$$ |$$ |_____ $$ \__$$ |$$ \__$$ |      $$ |__$$ |$$ |_____       $$ |_____ $$ |  $$ |        $$ $$/    _$$ |_ $$ |__$$ |$$ |  $$ |
 $$    $$/ $$    $$/ $$       |$$    $$/ $$    $$/       $$    $$/ $$       |      $$       |$$ |  $$ |         $$$/    / $$   |$$    $$/ $$ |  $$ |
  $$$$$$/   $$$$$$/  $$$$$$$$/  $$$$$$/   $$$$$$/        $$$$$$$/  $$$$$$$$/       $$$$$$$$/ $$/   $$/           $/     $$$$$$/ $$$$$$$/  $$/   $$/
)" << endl;
};

void JUEGOVIDA(tipoCelula *obj)
{
    for (int i = 0; i < 50; i++)
    {
        obj->MostrarMatriz();
        dormir(100);
        system("cls");
        obj->ProximoEstado();
    }
}

void AgregarCelula(tipoCelula *m)
{

    int x = 0, y = 0;
    do
    {
        cout << "\nIngresar posicion X de la particula: ";
        cin >> x;
        cout << "Ingresar posicion Y de la particula: ";
        cin >> y;

        if (!(m->Matriz::Limite2(x, y)))
        {
            cout << "\n¡Fuera de rango!" << endl;
        }
        else if (m->getCelulaPos(x, y).getEstado())
        {
            cout << "\n¡Existe una celula en esa posicion!" << endl;
        }

    } while ((!(m->Matriz::Limite2(x, y))) || (m->getCelulaPos(x, y).getEstado()));
    // condiciones del while = si está dentro de los límites o la célula a agregar está viva

    cout << endl;
    m->CambiarCelula(x, y);
}

void Menu()
{
    system("cls");
    tipoCelula *tipo = new tipoCelula;
    ASCCIjuegovida();
    int opcion = 0;
    do
    {
        cout << " " << endl;
        cout << "1). Dibujar tablero de la vida" << endl;
        cout << "2). Agregar una celula al tablero" << endl;
        cout << "3). Limpiar tablero" << endl;
        cout << "4). Escoger configuraciones iniciales" << endl;
        cout << "5). Iniciar juego de la vida" << endl;
        cout << "0). Salir del programa" << endl;
        cout << ">>";
        cin >> opcion;

        if (opcion == 1)
        {
            system("cls");
            tipo->MostrarMatriz();
        }
        else if (opcion == 2)
        {
            system("cls");
            AgregarCelula(tipo);
            tipo->MostrarMatriz();
        }
        else if (opcion == 3)
        {
            system("cls");
            tipo->LimpiarMatriz();
            tipo->MostrarMatriz();
        }
        else if (opcion == 4)
        {
            system("cls");
            VectorParticulas(tipo);
        }
        else if (opcion == 5)
        {
            system("cls");
            JUEGOVIDA(tipo);
            tipo->MostrarMatriz();
        }
    } while (opcion != 0);
    system("cls");
    cout << "Gracias por jugar :) xd" << endl;
}

int main() { Menu(); }