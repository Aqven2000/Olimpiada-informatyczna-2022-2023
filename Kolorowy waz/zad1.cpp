#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m,p,n;//m -> długość i szerokość planszy p-> liczbę przekąsek na planszy n-> liczbę poleceń do obsłużenia
    cin>>m>>p>>n;

    char mapa[m][m];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mapa[i][j] = '.';
            //cout<<mapa[i][j]<<" ";
        }
       // cout<<'\n';
    }
    mapa[0][0] = '0';//wstawianie weza
    int current_x = 0, current_y = 0,dlugosc_weza = 1;

    int Wi,Ki,Ci;//Wi->wiersz Ki->kolumna Ci->jedna przekąska o kolorze i
    for (int i = 0; i < p; i++)
    {
        cin>>Wi>>Ki>>Ci;
        mapa[Ki][Wi] = Ci+'0';
    }
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
           // mapa[i][j] = '.';
            cout<<mapa[i][j]<<" ";
        }
        cout<<'\n';
    }

    char skret;//w którą strone skręca wąż
    int Wj,Kj;//polecenie „Z w′j k′j” oznacza zapytanie o to, jaki kolor fragmentu węża w danym momencie znajduje się w polu w wierszu w′j i kolumnie k′j
    
    for (int i = 0; i < n; i++)
    {
        cin>>skret;
        if(skret == 'Z'){
            cin>>Wj>>Kj;
            if(mapa[Kj][Wj] != '.')
                
        }
        else{
            if(skret == 'P'){
                current_x += 1;
            }
            if(skret == 'L'){
                current_x -= 1;
            }
            if(skret == 'G'){
                current_y -= 1;
            }
            if(skret == 'D'){
                current_y += 1;
            }
            mapa[current_y][current_x] = '0';

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //     // mapa[i][j] = '.';
        //         cout<<mapa[i][j]<<" ";
        //     }
        // cout<<'\n';
        // }
        }
    }




    
    return 0;
}