#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
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

    
for (int z = 0; z < n; z++){
vector<int> pom_wynik;
j=0;
bool czy_break = false;
    for (int i = 0; i < n; i++)
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
    // wyniki.push_back(pom_wynik);
    if(!czy_break){
        pom[wyniki[wyniki.size()-1][sprawdzana]] = cala[wyniki[wyniki.size()-1][sprawdzana]];
        --sprawdzana;
    }
    else{
        wyniki.push_back(pom_wynik);
        if(pom_wynik.size() == NieCala.size()){
            for (int k = 0; k < NieCala.size(); k++)
            {
                indexy[pom_wynik[k]] = true;
            }
            
        }

        pom[wyniki[wyniki.size()-1][sprawdzana]] = -1;
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