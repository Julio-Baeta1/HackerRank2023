#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
First attempt:
From doing some examples it became apparant that all rows, columns and diagonals of length 3 must sum to 15 and thus the center block 
must equal 5 with opposite blocks around the center adding up to 10. Thus a map was used to check for duplicates with co-ordinates stored.
It became quickly apparent that this was the wrong approach as a digit could be in the wrong position and not detected as a duplicate 
until it appeared elsewhere.

Second attempt:
Since only the cost to change the given square to a magic square is required, then an alternative would be to calculate the cost to 
transform the given square to a proper magic square for all magic squares. Luckily from pen and paper it became quickly apparent that
there is only one magic sqaure with 8 permutations. From this it is quick to get the minimum score.

*/


int matDif(vector<vector<int>>& mat1, vector<vector<int>>& mat2)
// element-wise absolute difference of two matrices
{
    //assume matrix equal size
    int tot{0};
    for(int i = 0; i < mat1.size(); i++)
    {
        for(int j = 0; j < mat1.at(0).size(); j++)
            tot += abs(mat1.at(i).at(j) - mat2.at(i).at(j));
    }

    return tot;
}

int simpleMagic(vector<vector<int>> my_vec)
{
    vector<int> score{};
    //Set of valid 3x3 magic squares
    vector<vector<vector<int>>> magic{
        {{8,1,6},{3,5,7},{4,9,2}}, {{6,1,8},{7,5,3},{2,9,4}}, {{4,9,2},{3,5,7},{8,1,6}}, {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}}, {{4,3,8},{9,5,1},{2,7,6}}, {{6,7,2},{1,5,9},{8,3,4}}, {{2,7,6},{9,5,1},{4,3,8}}};

    for (auto square: magic)
        score.push_back(matDif(square,my_vec));

    return *min_element(score.begin(), score.end());
}

int main()
{
    const int magic{15};
    vector<vector<int>> myVec{{5,3,4},{1,5,8},{6,4,2}};

    int ans{};
    ans = simpleMagic(myVec);
    cout << ans;
 
    return 0;
}
