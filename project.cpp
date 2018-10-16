#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
int matrix[1005][1005];
int main (int argc, char  *argv[])
{
    int row, col, ans = 0;
    ifstream fin;
    string str1 = "\\matrix.data";
    string str2 = "\\final.peak";
    string input = argv[1]+str1;
    string output = argv[1]+str2;
    fin.open(input, ios::in);
    vector<pair<int,int>> anspos;
    vector<pair<int,int>>::iterator it;
    if (!fin){
        cout<<"in error"<<endl;
        return 0;
    }
    fin>>row>>col;
    //cout<<row<<col<<endl;
    for (int i=0; i<row;i++){
        for (int j = 0; j<col;j++){
            fin>>matrix[i][j];
            //cout<<matrix[i][j]<<" ";
        }
        //cout<<endl;
    }
    for (int i = 0;i<row;i++){
        for (int j = 0;j<col;j++){
            //cout<<i<<" "<<j<<endl;
            if (i > 0&&matrix[i][j]<matrix[i-1][j])continue;
            if (i<row-1&&matrix[i][j]<matrix[i+1][j])continue;
            if (j > 0&&matrix[i][j]<matrix[i][j-1])continue;
            if (j<col-1&&matrix[i][j]<matrix[i][j+1])continue;
            ans+=1;
            anspos.push_back(make_pair(i,j));
        }
    }
    fin.close( );
    ofstream fout;
    fout.open(output,ios::out);
    if (!fout){
        cout<<"out error"<<endl;
        return 0;
    }        
   // cout<<ans<<endl;
    fout<<ans<<endl;
    for (it = anspos.begin();it!=anspos.end();it++){
        fout<<it->first<<" "<<it->second<<endl;
    }
    fout.close();
    return 0;
}