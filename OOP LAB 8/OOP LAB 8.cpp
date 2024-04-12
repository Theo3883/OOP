#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <fstream>
std::ifstream fin("test.txt");
void to_lower(std::string& prop)
{
    int size = prop.size();
    for (int i = 0; i < size; i++)
        if (prop[i] >= 'A' && prop[i] <= 'Z')
            prop[i] += 32;
}
struct ceva
{
    int times;
    std::string word;
    bool operator < (const ceva& x) const
    {
        if(times < x.times)
            return 1;
        if (times == x.times)
            return word > x.word;
        return 0;
    }
};
int main()
{
    std::string prop;
    std::map <std::string, int> mapp;
    getline(fin, prop);
    to_lower(prop);
    auto stop = prop.find_first_of(" ?!.,");
    while (stop < prop.size())
    {
        if(stop>0)
            mapp[prop.substr(0, stop)]++;
        prop = prop.substr(stop + 1);
        stop = prop.find_first_of(" ?!.,");
    }
    std::priority_queue <ceva> q;
    for(auto it:mapp)
        q.push({it.second,it.first});
    while (!q.empty())
    {
        ceva temp = q.top();
        q.pop();
        std::cout << temp.word << "=>" << temp.times<<'\n';

    }  
}

