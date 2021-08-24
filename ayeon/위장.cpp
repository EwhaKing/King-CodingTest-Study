#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct clothe_type
{
    string type_name;
    int num;
};

struct Find
{
    string find_name;
    bool operator()(clothe_type c)
    {
        return find_name == c.type_name;
    }
};

int solution(vector<vector<string>> clothes) {
    vector<clothe_type> spy;

    // clothe_type
    for(int i=0; i<clothes.size(); i++)
    {
        Find f;
        f.find_name = clothes[i][1];

        vector<clothe_type>::iterator found;
        found = find_if(spy.begin(),spy.end(), f);

        if (found == spy.end())
        {
            clothe_type new_type;
            new_type.type_name = clothes[i][1];
            new_type.num = 1;
            spy.push_back(new_type);
        }
        else
        {
            found->num++;
        }
    }

    int mul=1;

    for(int i=0; i<spy.size(); i++)
    {
        mul *= (spy[i].num + 1);
    }

    return mul-1;
}
