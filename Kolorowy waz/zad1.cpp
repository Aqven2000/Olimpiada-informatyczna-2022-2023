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
    int current_x = 0, current_y = 0;
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

    //  for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < m; j++)
    //         {
    //         // mapa[i][j] = '.';
    //             cout<<mapa[i][j]<<" ";
    //         }
    //         cout<<'\n';
    //     }

    char skret;//w którą strone skręca wąż
    int Wj,Kj;//polecenie „Z w′j k′j” oznacza zapytanie o to, jaki kolor fragmentu węża w danym momencie znajduje się w polu w wierszu w′j i kolumnie k′j
    

    for (int i = 0; i < n; i++)
    {
        cin>>skret;
        if(skret == 'Z'){
            cin>>Wj>>Kj;
            
                bool czyBreak = false;
                for (int j = 0; j < kordynaty.size(); j++)
                {
                    if(kordynaty[j][0] == (Wj-1) && kordynaty[j][1] == (Kj-1)){
                        cout<<waz[j]<<endl;
                        czyBreak = true;
                        break;
                    }
                }
                if(!czyBreak)
                    if(mapa[Wj-1][Kj-1] !='.')
                        cout<<mapa[Wj-1][Kj-1]<<endl;
                    else
                        cout<<-1<<endl;
                
        }
        else{

            if(skret == 'P'){
                if(mapa[current_y][current_x+1] != '.'){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x+1);
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                }
                else{
                    mapa[current_y][current_x+1] = waz[0];
                   int tep_y = kordynaty[kordynaty.size()-1][0],tep_x = kordynaty[kordynaty.size()-1][1];

                    int kordynaktyKop[kordynaty.size()][2];

                    for (int k = 0; k < kordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = kordynaty[k][0];
                             kordynaktyKop[k][1] = kordynaty[k][1];
                    }
                    
                    for (int j = 1; j < waz.size(); j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                        //  mapa[kordynaty[j][0]][kordynaty[j][1]] = '.';
                          kordynaty[j][0] = kordynaktyKop[j-1][0];
                         kordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    kordynaty[0][1] = current_x+1;
                     mapa[tep_y][tep_x] = '.';
                }
                current_x += 1;
            }
            if(skret == 'L'){
                if(mapa[current_y][current_x-1] != '.'){
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x-1);
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y][current_x-1]);
                }
                else{
                  mapa[current_y][current_x-1] = waz[0];
                   int tep_y = kordynaty[kordynaty.size()-1][0],tep_x = kordynaty[kordynaty.size()-1][1];

                    int kordynaktyKop[kordynaty.size()][2];

                    for (int k = 0; k < kordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = kordynaty[k][0];
                             kordynaktyKop[k][1] = kordynaty[k][1];
                    }
                    
                    for (int j = 1; j < waz.size(); j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                        //  mapa[kordynaty[j][0]][kordynaty[j][1]] = '.';
                          kordynaty[j][0] = kordynaktyKop[j-1][0];
                         kordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    kordynaty[0][1] = current_x-1;
                     mapa[tep_y][tep_x] = '.';
                }
                current_x -= 1;
            }
            if(skret == 'G'){
                if(mapa[current_y-1][current_x] != '.'){
                    pomocnik.push_back(current_y-1);
                     pomocnik.push_back(current_x);
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y-1][current_x]);
                }
                else{
                    mapa[current_y-1][current_x] = waz[0];
                   int tep_y = kordynaty[kordynaty.size()-1][0],tep_x = kordynaty[kordynaty.size()-1][1];

                    int kordynaktyKop[kordynaty.size()][2];

                    for (int k = 0; k < kordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = kordynaty[k][0];
                             kordynaktyKop[k][1] = kordynaty[k][1];
                    }
                    
                    for (int j = 1; j < waz.size(); j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                        //  mapa[kordynaty[j][0]][kordynaty[j][1]] = '.';
                          kordynaty[j][0] = kordynaktyKop[j-1][0];
                         kordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    kordynaty[0][0] = current_y-1;
                     mapa[tep_y][tep_x] = '.';
                }
                current_y -= 1;
            }
            if(skret == 'D'){
                if(mapa[current_y+1][current_x] != '.'){
                    pomocnik.push_back(current_y+1);
                     pomocnik.push_back(current_x);
                    kordynaty.insert(kordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y+1][current_x]);
                }
                else{
                   mapa[current_y+1][current_x] = waz[0];
                   int tep_y = kordynaty[kordynaty.size()-1][0],tep_x = kordynaty[kordynaty.size()-1][1];

                    int kordynaktyKop[kordynaty.size()][2];

                    for (int k = 0; k < kordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = kordynaty[k][0];
                             kordynaktyKop[k][1] = kordynaty[k][1];
                    }
                    
                    for (int j = 1; j < waz.size(); j++)
                    {
                        mapa[kordynaty[j-1][0]][kordynaty[j-1][1]] = waz[j];
                        //  mapa[kordynaty[j][0]][kordynaty[j][1]] = '.';
                          kordynaty[j][0] = kordynaktyKop[j-1][0];
                         kordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    kordynaty[0][0] = current_y+1;
                     mapa[tep_y][tep_x] = '.';
                }
                current_y += 1;
            }
           // mapa[current_y][current_x] = '0';
            
            // for (int a = 0; a < m; a++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //     // mapa[i][j] = '.';
            //         cout<<mapa[a][j]<<" ";
            //     }
            // cout<<'\n';
            // }
            // cout<<endl;
            
            // cout<<endl;
            // for (int a = 0; a < kordynaty.size(); a++)
            // {
            //     cout<<waz[a]<<" ("<<kordynaty[a][0]<<" "<<kordynaty[a][1]<<") "<<endl;
            // }
            // cout<<endl;
            
        }
    }

    // for (auto i : waz)
    //     {
    //         cout<<i<< " ";
    //     }


    
    return 0;
}