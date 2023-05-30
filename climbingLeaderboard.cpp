#include <iostream>
#include <vector>
#include <map>

using namespace std;

void printVec(vector<int>& vec)
//print vector
{
    for(auto elem: vec)
        cout << elem << endl;
}

/*
Given a list of ranked leaderboard scores (descending order), obtain the rank for each of a new player's attempts (ascending order).
E.g. ranked: 100 90 90 80 are of respective ranks 1st, 2nd, 2nd, 3rd
So for player attempts 50 90 120 each is ranked as 4th, 2nd and 1st (Each player attempt is considered independantly)

First attempt: It is clear that we only care about ranking so making a map  map[rank] = score of unquie scores is easy from the 
descending order. Then all that is required is to climb up the rankings as player attempts is in ascending order. So compare each ranks
value to the current player attempt starting from the scoreboards bottom. If current postion on scoreboard score > player current score
then player rank = rank+1, else move up a slot on the scoreboard and compare again. Since player attempts are ranked in ascending order 
we can set the next player attempts scoreboard postion to be at minimum the same as the previous one
*/

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> attempts) 
{
    map<int,int> scoreboard;
    int pos{0}; //position on scoreboard
    vector<int> player_rank{}; 

    //set 1st to largest ranked score on scoreboard
    scoreboard.insert({++pos,*ranked.begin()});

    //insert unqiue ranked scores into correct positions on scoreboard 
    for(int i = 1; i <ranked.size(); i++)
    {
        if (ranked.at(i) < scoreboard[pos])
            scoreboard.insert({++pos,ranked.at(i)}); 
    }

    //If player's lowest attempt is lower than all scoreboard scores add it onto scoreboard.
    //Thus no special case is needed for attempts lower than bottom of the scoreboard.
    if(*attempts.begin() < scoreboard[pos-1])
        scoreboard.insert({++pos,*attempts.begin()}); 
    
    pos--;
    bool not_on_scoreboard{true}; //

    //For each player attempt
    for(auto& player_score: attempts)
    {   

        while(pos > 0 && not_on_scoreboard == true)
        {   

            if(player_score < scoreboard[pos])
            {
                player_rank.push_back(pos+1);
                not_on_scoreboard = false;
            }
            else if (player_score == scoreboard[pos])
            {
                player_rank.push_back(pos);
                not_on_scoreboard = false;
            }
            else
                pos--;
            
        }

        not_on_scoreboard = true;

        //When pos = 0, then attempt is the new highscore
        if(pos == 0)
            player_rank.push_back(1);
    }

    return player_rank;

}

int main()
{
    vector<int> ranked{100,90,90,80,75,60};//{100,100,50,40,40,20,10};
    vector<int> attempts{50,50,55,55,60,77,90,102,120,120};//{5,25,50,120}; 
    vector<int> ranks{};

    ranks = climbingLeaderboard(ranked,attempts);
    printVec(ranks);

    return 0;
}