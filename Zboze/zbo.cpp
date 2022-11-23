#include <bits/stdc++.h>

using namespace std;

int main(){

     ios_base::sync_with_stdio(0);
     cin.tie(0);

    int k,n;
    cin>>n>>k;
    vector<vector<int> > odleglosci;
    vector<int> pom1_odleglosci;

    vector<vector<int> > odleglosci_pom2;

    for (int i = 0; i < n-1; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pom1_odleglosci.push_back(a);
        pom1_odleglosci.push_back(b);
        pom1_odleglosci.push_back(c);
        odleglosci.push_back(pom1_odleglosci);
        odleglosci_pom2.push_back(pom1_odleglosci);
        pom1_odleglosci.clear();
    }

    // for (int i = 0; i < odleglosci.size(); i++)
    // {
    //     for (int j = 0; j < odleglosci[i].size(); j++)
    //     {
    //         cout<<odleglosci[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    int d,suma = 0;

    for (int i = 1; i <= k; i++)
    {
        cin>>d;
        // map<int,int> droga_zasob;
        int j = 0;
        while (j< odleglosci_pom2.size())
        {
                if(odleglosci_pom2[j][0] == d){
                    // droga_zasob[odleglosci[j][1]] = odleglosci[j][2];
                    suma+=odleglosci_pom2[j][2];
                    if(odleglosci_pom2[j][1] != 1)
                        d = odleglosci_pom2[j][1];
                    else
                        break;

                    odleglosci_pom2[j][0] = -1;
                    odleglosci_pom2[j][1] = -1;
                    odleglosci_pom2[j][2] = -1;
                    // cout<<odleglosci_pom2[j][0]<<odleglosci_pom2[j][1]<<odleglosci_pom2[j][2]<<endl;
                    j=-1;
                }
                else if(odleglosci_pom2[j][1] == d){
                    // droga_zasob[odleglosci[j][0]] = odleglosci[j][2];
                    suma+=odleglosci_pom2[j][2];
                    if(odleglosci_pom2[j][0] != 1)
                        d = odleglosci_pom2[j][0];
                    else
                        break;
                    odleglosci_pom2[j][0] = -1;
                    odleglosci_pom2[j][1] = -1;
                    odleglosci_pom2[j][2] = -1;
                    // cout<<odleglosci_pom2[j][0]<<odleglosci_pom2[j][1]<<odleglosci_pom2[j][2]<<endl;
                    j=-1;
                }

                

                cout<<" d: "<<d<<" suma: "<<suma<<endl;

                // if((odleglosci_pom2[j][1] == 1 && odleglosci_pom2[j][0] == d )|| (odleglosci_pom2[j][0] == 1 && odleglosci_pom2[j][1] == d ))
                //     break;
                j++;
        }
        // for (auto k = droga_zasob.begin(); k != droga_zasob.end(); k++)
        // {
        //     cout<<k->first<<" "<<k->second<<endl;
        // }
        cout<<suma*2*i<<'\n';

        odleglosci_pom2.clear();
        odleglosci_pom2.insert(odleglosci_pom2.begin(),odleglosci.begin(),odleglosci.end());

    }

    return 0;
}