//
// Created by neriy on 05/09/2022.
//

#include "neriya_yael_converter.h"


using namespace std;

set<int> convertVector2Set (const vector<int> &vector1){
    set<int> res(vector1.begin(),vector1.end());
    return res;
}
vector<int> convertSet2Vec (set<int> &the_set){
    vector<int> res(the_set.begin(), the_set.end());
    return res;
}
vector<int> convertSet2Veclvalue (const set<int>& the_set){
    vector<int> res(the_set.begin(), the_set.end());
    return res;
}
/**
 * convert [0,0,0,1,1,0] to [3,4].
 * @param vector1
 * @return
 */
vector<int> convert_bool_vec_2_indicies_vec(const vector<bool> &vector1){
    vector<int> res;
    for (int i = 0; i < vector1.size(); ++i) {
        if (vector1[i]) res.push_back(i);
    }
    return res;
}



nNetwork convertYaelNW2NerNW(yNetwork &network ){
    nNetwork res;
    int i = 0;
    for (const auto& vec:network) {
//        if(vec.empty())
//            continue;
        res[i] = convertVector2Set(vec);
        i++;
    }
    return res;
}
yNetwork convertNerNW2YaelNW(nNetwork &network, int n){
    yNetwork res;
    res.reserve(n);


    vector<int> keys;
    transform(network.begin(), network.end(), back_inserter(keys), RetrieveKey()); // todo understand how it works
    sort(keys.begin(),keys.end());

    int i = 0;
    for (const auto& key:keys) {
        // add nodes that had no connection, and aren't in nNetwork, but should appear in yNetwork.
        while(key!=i){
            res.emplace_back();
            i++;
        }
        if(i < n-1) {
            res.push_back(convertSet2Vec(network[key]));
            i++;
        }
    }
    return res;
}
