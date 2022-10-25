#include <iostream>
#include <vector>

using namespace std;

// void nawiasowanie(vector<char> w, int H, int odwrucenia){
//     if(nawiasy.size() == 0)
//         H = 0;
//     else if()
// }


int main(){
    int n,H;
    cin>>n>>H;

    vector<char> nawiasy;

    for (int i = 0; i < n; i++)
    {
        char a;
        cin>>a;
        nawiasy.push_back(a);
    }
    int zlicz =0;
    for (int i = H-1; i < n-(H-1); i++)
    {
       bool czyPrawo;
       if(nawiasy[i-1] == '(')
        czyPrawo = true;
       else
        czyPrawo = false;

        
        if(czyPrawo && i != H-1 && nawiasy[i] != ')'){
            nawiasy[i] = ')';
            zlicz++;
        }
        else if(!czyPrawo && i != H-1 && nawiasy[i] == ')'){
            nawiasy[i] = '(';
            zlicz++;
        }
        else if(i == H-1 && nawiasy[i] == ')'){
            nawiasy[i] = '(';
            zlicz++;
        }
    }

    

    // for (auto i : nawiasy)
    // {
    //     cout<<i;
    // }
    // cout<<'\n';
    cout<<zlicz<<'\n';
    
    
    
    return 0;
}