#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;

    cin>>n>>m>>k;
vector<int> cala;
vector<int> pom;

for (int i = 0; i < n; i++)
{
    int a;
    cin>>a;
    cala.push_back(a);
    pom.push_back(a);
}

vector<int> NieCala;

for (int i = 0; i < m; i++)
{
    int a;
    cin>>a;
    NieCala.push_back(a);
}
int j = 0;
vector<vector<int> > wyniki;
int sprawdzana = m-1;
map<int, bool> indexy;

while(sprawdzana>=0){
    vector<int> pom_wynik;
    j=0;
    int i = 0;
    bool czy_break = false;
    int zlicz_min_one = 0;
        for (i = 0; i < pom.size(); i++)
        {
            if(pom[i] == NieCala[j]){
                pom_wynik.push_back(i);
                j++;
            }

            if(j == NieCala.size()){
                j=0;
                czy_break = true;
                break;
            }
            
        }

        if(!czy_break){
            
            for (int h = pom.size()-1; h >= wyniki[wyniki.size()-1][sprawdzana]; h--)
            {
                pom.pop_back();
            }

            NieCala.pop_back();
            if(pom.size() <=0){
                break;
            }

            for (int h = 0; h < pom.size(); h++)
            {
                pom[h] = cala[h];
            }
            
             --sprawdzana;
            czy_break = false;
        }
        else{
             wyniki.push_back(pom_wynik);


        pom[wyniki[wyniki.size()-1][sprawdzana]] = -1;
        ++zlicz_min_one;
    }
    if(zlicz_min_one == pom.size())
        break;
}


for (int i = 0; i < wyniki.size(); i++)
{
    for (int j = 0; j < wyniki[i].size(); j++)
    {
        indexy[wyniki[i][j]] = true;
    }
}

for (int i = 0; i < n; i++)
{
    if(indexy.find(i) != indexy.end())
        cout<<1<<" ";
    else
        cout<<0<<" ";
}


    return 0;
}