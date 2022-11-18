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






return 0;
}