//
// Created by neriy on 01/09/2022.
//

#ifndef FIRST_AID_UTILITY_FUNCTIONS_H
#define FIRST_AID_UTILITY_FUNCTIONS_H

//
// Created by neriy on 01/09/2022.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <unordered_set>
#include "neriya_yael_converter.h"

#define nNetwork map<int,set<int>>
#define yNetwork vector<vector<int>>

using namespace std;

void remove_node_from_network(nNetwork &network, const int removed_id);
void print_nNW(map<int, set<int>> &n) ;
set<int> get_cluster_of_node_BFS(nNetwork &network, int node_in_cluster);
void subtract_sec_from_first(set<int> &a, set<int> &b);

/**
 * returns the functional component = giant+reinforced clusters.
 * @param network
 * @param node_in_cluster
 * @param reinforced vector of rein
 * @return
 */
set<int> get_functional(nNetwork &network, int node_in_cluster, const vector<int>& reinforced);

void print_my_set(set<int> s);


#endif //FIRST_AID_UTILITY_FUNCTIONS_H
