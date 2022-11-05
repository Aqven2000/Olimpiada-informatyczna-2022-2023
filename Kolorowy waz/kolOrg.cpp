#include <iostream>
#include <vector>
#include <string> 
#include <fstream> 

using namespace std;

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    int m,p,n;//m -> długość i szerokość planszy p-> liczbę przekąsek na planszy n-> liczbę poleceń do obsłużenia
    cin>>m>>p>>n;
    vector<string> row;
    vector<vector<string> > mapa;

    for (int i = 0; i < m; i++)
    {
        vector<string> row;
        for (int j = 0; j < m; j++)
        {
            row.push_back(".");
            //cout<<mapa[i][j]<<" ";
        }
        mapa.push_back(row);
        //cout<<'\n';
    }
    mapa[0][0] = "0";//wstawianie weza
    int current_x = 0, current_y = 0;
    vector<string> waz{"0"};
    vector<vector<int> > koordynaty;
    vector<int> pomocnik;
    
    pomocnik.push_back(current_y);
    pomocnik.push_back(current_x);
    koordynaty.push_back(pomocnik);
    pomocnik.clear();
    // cout<<koordynaty[0][0]<<" "<<koordynaty[0][1]<<endl;

    int Wi,Ki,Ci;//Wi->wiersz Ki->kolumna Ci->jedna przekąska o kolorze i
    for (int i = 0; i < p; i++)
    {
        cin>>Wi>>Ki>>Ci;
        mapa[Wi-1][Ki-1] = to_string(Ci);
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
    ofstream out("odp.txt");

    for (int i = 0; i < n; i++)
    {
        cin>>skret;
        if(skret == 'Z'){
            cin>>Wj>>Kj;
            
                bool czyBreak = false;
                for (int j = 0; j < koordynaty.size(); j++)
                {
                    if((koordynaty[j][0] == (Wj-1)) && (koordynaty[j][1] == (Kj-1))){
                        cout<<waz[j]<<endl;
                        out<<waz[j]<<endl;
                        czyBreak = true;
                        break;
                    }
                }
                if(!czyBreak){
                        cout<<-1<<endl;
                        out<<-1<<endl;
                }
        }
        else{

            if(skret == 'P'){
                if(mapa[current_y][current_x+1] != "."){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x+1);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                }
                else{
                    mapa[current_y][current_x+1] = waz[0];
                   int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];

                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                        mapa[koordynaty[j-1][0]][koordynaty[j-1][1]] = waz[j];
                        //  mapa[koordynaty[j][0]][koordynaty[j][1]] = '.';
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][1] = current_x+1;
                     mapa[tep_y][tep_x] = ".";
                }
                current_x += 1;
            }
            if(skret == 'L'){
                if(mapa[current_y][current_x-1] != "."){
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x-1);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y][current_x-1]);
                }
                else{
                  mapa[current_y][current_x-1] = waz[0];
                   int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];

                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    // if(waz.size()>1)
                        for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                        {
                            mapa[koordynaty[j-1][0]][koordynaty[j-1][1]] = waz[j];
                            //  mapa[koordynaty[j][0]][koordynaty[j][1]] = '.';
                            koordynaty[j][0] = kordynaktyKop[j-1][0];
                            koordynaty[j][1] = kordynaktyKop[j-1][1];
                        }
                    koordynaty[0][1] = current_x-1;
                     mapa[tep_y][tep_x] = ".";
                }
                current_x -= 1;
            }
            if(skret == 'G'){
                if(mapa[current_y-1][current_x] != "."){
                    pomocnik.push_back(current_y-1);
                     pomocnik.push_back(current_x);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y-1][current_x]);
                }
                else{
                    mapa[current_y-1][current_x] = waz[0];
                   int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];

                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                        mapa[koordynaty[j-1][0]][koordynaty[j-1][1]] = waz[j];
                        //  mapa[koordynaty[j][0]][koordynaty[j][1]] = '.';
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][0] = current_y-1;
                     mapa[tep_y][tep_x] = ".";
                }
                current_y -= 1;
            }
            if(skret == 'D'){
                if(mapa[current_y+1][current_x] != "."){
                    pomocnik.push_back(current_y+1);
                     pomocnik.push_back(current_x);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),mapa[current_y+1][current_x]);
                }
                else{
                   mapa[current_y+1][current_x] = waz[0];
                   int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];

                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                        mapa[koordynaty[j-1][0]][koordynaty[j-1][1]] = waz[j];
                        //  mapa[koordynaty[j][0]][koordynaty[j][1]] = '.';
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][0] = current_y+1;
                     mapa[tep_y][tep_x] = ".";
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
            // for (int a = 0; a < koordynaty.size(); a++)
            // {
            //     cout<<waz[a]<<" ("<<koordynaty[a][0]<<" "<<koordynaty[a][1]<<") "<<endl;
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