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
    vector<char> waz{'0'};
    vector<vector<int> > kordynaty;
    vector<int> pomocnik;
    
    pomocnik.push_back(current_y);
    pomocnik.push_back(current_x);
    kordynaty.push_back(pomocnik);
    pomocnik.clear();
    // cout<<kordynaty[0][0]<<" "<<kordynaty[0][1]<<endl;

    int Wi,Ki,Ci;//Wi->wiersz Ki->kolumna Ci->jedna przekąska o kolorze i
    for (int i = 0; i < p; i++)
    {
        cin>>Wi>>Ki>>Ci;
        mapa[Wi-1][Ki-1] = Ci+'0';
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
            if(mapa[Wj-1][Kj-1] !='.')
                cout<<mapa[Wj-1][Kj-1]<<endl;
            else
                cout<<-1<<endl;
                
        }
        else{

            if(skret == 'P'){
                if(mapa[current_y][current_x+1] != '.'){
                    dlugosc_weza++;
                    waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik[0] = current_y;
                     pomocnik[1] = current_x+1;
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                }
                else{
                    mapa[current_y][current_x+1] = waz[0];
                    for (int j = 1; j < dlugosc_weza; j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                    }
                     mapa[kordynaty[kordynaty.size()-1][0]][kordynaty[kordynaty.size()-1][1]] = '.';
                }
                current_x += 1;
            }
            if(skret == 'L'){
                if(mapa[current_y][current_x-1] != '.'){
                    dlugosc_weza++;
                    waz.insert(waz.begin(),mapa[current_y][current_x-1]);
                    pomocnik[0] = current_y;
                     pomocnik[1] = current_x-1;
                     kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                }
                else{
                    mapa[kordynaty[0][0]][kordynaty[0][1]-1] = waz[0];
                    for (int j = 1; j < dlugosc_weza; j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                    }
                    mapa[kordynaty[kordynaty.size()-1][0]][kordynaty[kordynaty.size()-1][1]] = '.';
                }
                current_x -= 1;
            }
            if(skret == 'G'){
                if(mapa[current_y-1][current_x] != '.'){
                    dlugosc_weza++;
                    waz.insert(waz.begin(),mapa[current_y-1][current_x]);
                    pomocnik[0] = current_y-1;
                     pomocnik[1] = current_x;
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                }
                else{
                    mapa[kordynaty[0][0]-1][kordynaty[0][1]] = waz[0];
                    for (int j = 1; j < dlugosc_weza; j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                    }
                    mapa[kordynaty[kordynaty.size()-1][0]][kordynaty[kordynaty.size()-1][1]] = '.';
                }
                current_y -= 1;
            }
            if(skret == 'D'){
                if(mapa[current_y+1][current_x] != '.'){
                    dlugosc_weza++;
                    waz.insert(waz.begin(),mapa[current_y+1][current_x]);
                    pomocnik[0] = current_y+1;
                     pomocnik[1] = current_x;
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                }
                else{
                    mapa[kordynaty[0][0]+1][kordynaty[0][1]] = waz[0];
                    for (int j = 1; j < dlugosc_weza; j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                    }
                    mapa[kordynaty[kordynaty.size()-1][0]][kordynaty[kordynaty.size()-1][1]] = '.';
                }
                current_y += 1;
            }
           // mapa[current_y][current_x] = '0';
            
            for (int a = 0; a < m; a++)
            {
                for (int j = 0; j < m; j++)
                {
                // mapa[i][j] = '.';
                    cout<<mapa[a][j]<<" ";
                }
            cout<<'\n';
            }
            cout<<endl;
            for (auto i : waz)
            {
                cout<<i<< " ";
            }
            cout<<endl;
            for (int a = 0; a < kordynaty.size(); a++)
            {
                cout<<kordynaty[a][0]<<" "<<kordynaty[a][1]<<endl;
            }
            cout<<endl;
            
        }
    }

    // for (auto i : waz)
    //     {
    //         cout<<i<< " ";
    //     }


    
    return 0;
}