#include<iostream>
#include<string>
#include<stack>

using namespace std;

/*
Morgan wishes to combined two strings such that the smallest front letter is added first, like a stack for strings

Attempt 1: Followed the prompt and inserted both strings into stack, compared the top of each stack with code to consider the case for
repeating letter segments. This repeating code would make a new stack to which both could add to until a difference occured, which would
allow a comparison to occur. This was very ineffcient.

Attempt 2: Instead of stacks a pair of string iterators was used for each string. The first iterator pointed to the current letter 
position and the second iterator to the character after a repeating sub-string that appeared in both strings. However this method also
failed some test cases so further debugging is required.
*/

string morganAndString(string a, string b) {

    string::iterator a_iter = a.begin(), b_iter = b.begin(), rep_a_end = a.begin(), rep_b_end = b.begin();
    string min_string;

    int diff{0};

    while(a_iter != a.end() && b_iter != b.end())
    {       
        if(*a_iter == *b_iter)
        {
            if (a_iter < rep_a_end && b_iter < rep_b_end)
            {
                if(diff > 0)
                {
                    min_string += *a_iter;
                    a_iter++;
                }
                else if(diff < 0)
                {
                    min_string += *b_iter;
                    b_iter++;
                }
            }
            else
            {
                rep_a_end = a_iter;
                rep_b_end = b_iter;
                while(*rep_a_end == *rep_b_end && rep_a_end != a.end() && rep_b_end != b.end())
                {
                    rep_a_end++;
                    rep_b_end++;          
                }

                if(*rep_a_end < *rep_b_end || rep_a_end == a.end())
                {
                    diff = 1;
                    min_string += *a_iter;
                    a_iter++;
                }
                else if (*rep_a_end > *rep_b_end || rep_b_end == b.end())
                {
                    diff = -1;
                    min_string += *b_iter;
                    b_iter++;
                }
                else
                    diff = 0;
            }
        }
        else if(*a_iter < *b_iter)
        {
            min_string += *a_iter;
            a_iter++;
        }
        else if(*a_iter > *b_iter)
        {
            min_string += *b_iter;
            b_iter++;
        }
    }

    for(string::iterator i = b_iter; i < b.end(); i++)
        min_string += *i;
    for(string::iterator i = a_iter; i < a.end(); i++)
        min_string += *i;

    return min_string;
}

int main()
{
    string first{"AAABBAABBBBAA"};//{"JACK"};//{"ACA"};//{"ABACABA"};//{"ABCXYZK"};
    string second{"BBAAABBBAB"};//{"DANIEL"};//{"BCF"};//{"ABACABA"};//{"XYZA"};
    string ans = morganAndString(first,second);
    cout << ans << endl;

    return 0;
}
