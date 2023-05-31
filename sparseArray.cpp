#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


vector<int> matchingStrings(vector<string> string_list, vector<string> queries) 
{
    map<string,int> unique_strings;
    map<string,int>::iterator iter; 
    vector<int> matched(queries.size(),0); //zero vector with dims of queries

    //Insert each string from string list into unique_strings map with occurence count=1, if it is already there increment the 
    //counter by 1.
    for(auto& s: string_list)
    {
        iter = unique_strings.find(s);
        if (iter != unique_strings.end())
            iter->second++;
        else
            unique_strings[s] = 1;
    }

    //Search unique_strings map for each query, if found set relavent position in matched vector to the strings count value.
    for(int i=0; i<queries.size(); i++)
    {
        iter = unique_strings.find(queries.at(i));
        if (iter != unique_strings.end())
            matched.at(i) = iter->second;
    }

    return matched;

}

int main()
{
    vector<string> string_list{"abcde","sdaklfj","asdjf","na","basdn","sdaklfj","asdjf","na","asdjf","na","basdn","sdaklfj","asdjf"};
    //{"def","de","fgh"};//{"aba","baba","aba","xzxb"};
    vector<string> queries{"abcde","sdaklfj","asdjf","na","basdn"};
    //{"de","lmn","fgh"};//{"aba","xzxb","ab"};

    vector<int> ans;

    ans = matchingStrings(string_list,queries);

    for(auto& line: ans)
        cout << line << endl;

    return 0 ;
}
