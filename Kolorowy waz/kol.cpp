// #include <iostream>
// #include <vector>
// #include <string> 
#include <bits/stdc++.h>

using namespace std;

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);
    int m,p,n;//m -> długość i szerokość planszy p-> liczbę przekąsek na planszy n-> liczbę poleceń do obsłużenia
    cin>>m>>p>>n;

    
    int current_x = 0, current_y = 0;
    vector<string> waz{"0"};
    vector<vector<int> > koordynaty;
    vector<int> pomocnik;

    vector<string> Kolory;
    vector<vector<int> > koordynaty_Kolorow;
    vector<int> pomocnik_Kolorow;
    
    pomocnik.push_back(current_y);
    pomocnik.push_back(current_x);
    koordynaty.push_back(pomocnik);
    pomocnik.clear();
    // cout<<koordynaty[0][0]<<" "<<koordynaty[0][1]<<endl;

    int Wi,Ki,Ci;//Wi->wiersz Ki->kolumna Ci->jedna przekąska o kolorze i
    for (int i = 0; i < p; i++)
    {
        cin>>Wi>>Ki>>Ci;

        pomocnik_Kolorow.push_back(Wi-1);
        pomocnik_Kolorow.push_back(Ki-1);

        Kolory.push_back(to_string(Ci));
        koordynaty_Kolorow.push_back(pomocnik_Kolorow);
        pomocnik_Kolorow.clear();
    }

        // for (int f = 0; f < koordynaty_Kolorow.size(); f++){
        //     cout<<"("<<koordynaty_Kolorow[f][0]<<","<<koordynaty_Kolorow[f][1]<<")\n";
        // }
        // cout<<"\n";
    

    char skret;//w którą strone skręca wąż
    int Wj,Kj;//polecenie „Z w′j k′j” oznacza zapytanie o to, jaki kolor fragmentu węża w danym momencie znajduje się w polu w wierszu w′j i kolumnie k′j
   

    for (int i = 0; i < n; i++)
    {
        cin>>skret;
        if(skret == 'Z'){
            cin>>Wj>>Kj;
            
                bool czyBreak = false;
                for (int j = 0; j < koordynaty.size(); j++)
                {
                    if((koordynaty[j][0] == (Wj-1)) && (koordynaty[j][1] == (Kj-1))){
                        cout<<waz[j]<<'\n';
                        czyBreak = true;
                        break;
                    }
                }
                if(!czyBreak){
                        cout<<-1<<'\n';
                }
        }
        else{

            if(skret == 'P'){
                bool czyWykonano = false;
             for(int g = 0;g < koordynaty_Kolorow.size();g++){
                if((koordynaty[0][1]+1 == koordynaty_Kolorow[g][1])  && (koordynaty[0][0] == koordynaty_Kolorow[g][0])){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x+1);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),Kolory[g]);
                    koordynaty_Kolorow.erase(koordynaty_Kolorow.begin()+g);
                    Kolory.erase(Kolory.begin()+g);
                    czyWykonano = true;
                    break;
                }
             }
                 if(!czyWykonano){
                    // koordynaty[0][1]++;
                   //int tep = ++koordynaty[0][1];
                       int tep_y = koordynaty[0][0],tep_x = koordynaty[0][1]+1;

                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    // koordynaty[0][1] = current_x+1;
                    koordynaty[0][1] = tep_x;
                    koordynaty[0][0] = tep_y;
                }
                current_x += 1;
            }
            if(skret == 'L'){
                bool czyWykonano = false;
            for(int g = 0;g < koordynaty_Kolorow.size();g++){
                if((koordynaty[0][1]-1 == koordynaty_Kolorow[g][1]) && (koordynaty[0][0] == koordynaty_Kolorow[g][0])){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y);
                     pomocnik.push_back(current_x-1);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),Kolory[g]);
                    koordynaty_Kolorow.erase(koordynaty_Kolorow.begin()+g);
                    Kolory.erase(Kolory.begin()+g);
                    czyWykonano = true;
                    break;
                }
            }
                if(!czyWykonano){
                //   koordynaty[0][1]--;
                //    int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];
                    int tep_y = koordynaty[0][0],tep_x = koordynaty[0][1]-1;
                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][1]= tep_x;
                    koordynaty[0][0]= tep_y;
                }
                current_x -= 1;
            }
            if(skret == 'G'){
                bool czyWykonano = false;
                for(int g = 0;g < koordynaty_Kolorow.size();g++) { 
                 if((koordynaty[0][0]-1 == koordynaty_Kolorow[g][0]) && (koordynaty[0][1] == koordynaty_Kolorow[g][1])){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y-1);
                     pomocnik.push_back(current_x);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),Kolory[g]);
                    koordynaty_Kolorow.erase(koordynaty_Kolorow.begin()+g);
                    Kolory.erase(Kolory.begin()+g);
                    czyWykonano = true;
                    break;
                }
                }
                if(!czyWykonano){
                    // koordynaty[0][0]--;
                //    int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];
                    int tep_y = koordynaty[0][0]-1,tep_x = koordynaty[0][1];
                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][0]= tep_y;
                    koordynaty[0][1] = tep_x;
                }
                current_y -= 1;
            }
            if(skret == 'D'){
                bool czyWykonano = false;
                for(int g = 0;g < koordynaty_Kolorow.size();g++)   
                 if((koordynaty[0][0]+1 == koordynaty_Kolorow[g][0]) && (koordynaty[0][1] == koordynaty_Kolorow[g][1])){
                    // waz.insert(waz.begin(),mapa[current_y][current_x+1]);
                    pomocnik.push_back(current_y+1);
                     pomocnik.push_back(current_x);
                    koordynaty.insert(koordynaty.begin(),pomocnik);
                    pomocnik.clear();
                    waz.insert(waz.begin(),Kolory[g]);
                    koordynaty_Kolorow.erase(koordynaty_Kolorow.begin()+g);
                    Kolory.erase(Kolory.begin()+g);
                    czyWykonano = true;
                    break;
                }
                if(!czyWykonano){
                //    koordynaty[0][0]++;
                //    int tep_y = koordynaty[koordynaty.size()-1][0],tep_x = koordynaty[koordynaty.size()-1][1];
                    int tep_y = koordynaty[0][0]+1,tep_x = koordynaty[0][1];
                    int kordynaktyKop[koordynaty.size()][2];

                    for (int k = 0; k < koordynaty.size(); k++)
                    {
                            kordynaktyKop[k][0] = koordynaty[k][0];
                             kordynaktyKop[k][1] = koordynaty[k][1];
                    }
                    
                    for (int j = waz.size()-1; j >= 1; j--)//---------------------------------
                    {
                          koordynaty[j][0] = kordynaktyKop[j-1][0];
                         koordynaty[j][1] = kordynaktyKop[j-1][1];
                    }
                    koordynaty[0][0] = tep_y;
                    koordynaty[0][1] = tep_x;
                }
                current_y += 1;
            }
           
        // for (int f = 0; f < koordynaty.size(); f++){
        //     cout<<"("<<koordynaty[f][0]<<","<<koordynaty[f][1]<<") "<<waz[f]<<"\n";
        // }
        // cout<<'\n';
        // for (int f = 0; f < koordynaty_Kolorow.size(); f++){
        //     cout<<"("<<koordynaty_Kolorow[f][0]<<","<<koordynaty_Kolorow[f][1]<<") "<<Kolory[f]<<"\n";
        // }
        // cout<<"\n";

        }
    }

    // for (auto i : waz)
    //     {
    //         cout<<i<< " ";
    //     }


    
    return 0;
}