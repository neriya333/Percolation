//
// Created by neriy on 05/09/2022.
//

#ifndef FIRST_AID_LOGIC_H
#define FIRST_AID_LOGIC_H

#include "utility_functions.h"

/**
 * return the functioning component. (in case the network wasn't build before calling the function)
 * @param network1
 * @param network2
 * @param node_in_cluster
 * @param reinforced
 * @return
 */
set<int> conjunction_functional(nNetwork network1, nNetwork network2, int node_in_cluster, const vector<int>& reinforced);
/**
 * return the functioning component. (in case the network WAS build before calling the function)
 * differance:
 * @param network1 is &network1, not network1
 * @param network2
 * @param node_in_cluster
 * @param reinforced
 * @return
 */
set<int> conjunction_functional(nNetwork &network1, nNetwork &network2, int node_in_cluster, const vector<int>& reinforced);
/**
 * Inset to vector<vector<int>>
 * @param network1 vector<vector<int>>
 * @param network2 vector<vector<int>>
 * @param node_in_cluster size of network
 * @param reinforced vector<bool> [size of network]
 * @return vector<int> the giant component
 */
vector<int> conjunction_functional_translator(yNetwork &network1, yNetwork &network2, int node_in_cluster, const vector<bool>& reinforced);

#endif //FIRST_AID_LOGIC_H
