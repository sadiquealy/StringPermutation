#include <algorithm>
#include <iostream>
#include <string>
#include<vector>

using namespace std;

/**
 * @brief String comb utility function
 * @param pos
 * @param str
 * @param res
 */
void stringPermuteUtil(size_t pos, const std::string&  str, vector<std::string>& res)
{
    size_t length = str.length();
    for(size_t i = pos;i<length;i++)
    {
        std::string combStr(str);
        std::swap(combStr[pos], combStr[i]);
        if(i!=pos )
        {         
            res.push_back(combStr);          
        }

       stringPermuteUtil(pos+1,combStr, res);

    }
}

/**
 * @brief stringComb
 * @param str
 * @return
 */
vector<std::string> stringPermute(const std::string & str)
{
    vector<std::string> listStr;
    listStr.push_back(str);
    stringPermuteUtil(0, str, listStr);
    return listStr;
}

int main()
{
    string test("ABCD");
    vector<std::string> listStr = stringPermute(test);
    size_t combStrLength = listStr.size();
    cout<<"Input is:"<<test<<endl;
    cout<<"Total Permutation count is:"<<combStrLength<<endl;
    auto it = std::unique( listStr.begin(), listStr.end() );
    bool wasUnique = (it == listStr.end() );
    cout<<"All Elements are unique:"<< std::boolalpha << wasUnique << endl;
    cout<<"Elements Are:";
    for(auto& it:listStr)
    {
       cout<<endl<<it;
    }

    return 0;
}
