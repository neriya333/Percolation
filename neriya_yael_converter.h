//
// Created by neriy on 05/09/2022.
//

#ifndef FIRST_AID_NERIYA_YAEL_CONVERTER_H
#define FIRST_AID_NERIYA_YAEL_CONVERTER_H

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <unordered_set>
#include <map>
#define nNetwork map<int,set<int>>
#define yNetwork vector<vector<int>>

using namespace std;

// todo understand how it works
struct RetrieveKey
{
    template <typename T>
    typename T::first_type operator()(T keyValuePair) const
    {
        return keyValuePair.first;
    }
};
// todo understand how it works end of todo

set<int> convertVector2Set (const vector<int> &vector1);
vector<int> convertSet2Vec (set<int> &the_set);
vector<int> convertSet2Veclvalue (const set<int>& the_set);

/**
 * convert vec<bool> = [0,0,0,1,1,0] to vec<int> = [3,4]
 * @param vector1
 * @return
 */
vector<int> convert_bool_vec_2_indicies_vec(const vector<bool> &vector1);
/**
 * convert Yael's NW to Neriya's
 * @param network
 * @return
 */
nNetwork convertYaelNW2NerNW(yNetwork &network );
/**
 * convert Neriya's NW to Yeals
 * @param network
 * @return
 */
yNetwork convertNerNW2YaelNW(nNetwork &network, int n);


#endif //FIRST_AID_NERIYA_YAEL_CONVERTER_H
