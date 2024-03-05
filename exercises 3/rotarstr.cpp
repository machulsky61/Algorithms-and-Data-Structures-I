#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j) {
    string v;
    int k = s.size() - (j % s.size());
    for(int i = k; i < s.size(); i++){
        v.push_back(s[i]);
    }
    for(int i = 0; i < k; i++){
        v.push_back(s[i]);
    }
    return v;
}

int main()
{
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
