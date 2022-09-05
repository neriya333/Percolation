//
// Created by neriy on 05/09/2022.
//

#include "logic.h"

/**
 * return the functioning component. (in case the network wasn't build before calling the function)
 * @param network1
 * @param network2
 * @param node_in_cluster
 * @param reinforced
 * @return
 */
set<int> conjunction_functional(nNetwork network1, nNetwork network2, int node_in_cluster, const vector<int>& reinforced){
    set<int> functioning_c_1 = get_functional(network1, node_in_cluster, reinforced);
    set<int> functioning_c_2 = get_functional(network2, node_in_cluster, reinforced);
    set<int> nodes_to_remove;
    int old_shape1 = functioning_c_1.size(),old_shape2 = functioning_c_2.size();

    while(true) {
        subtract_sec_from_first(functioning_c_1, functioning_c_2); // remove nodes in A and not in B(from A)
        for (auto node_id:functioning_c_1){
            remove_node_from_network(network1, node_id);
        }
        functioning_c_1 = get_functional(network1, node_in_cluster, reinforced);

        subtract_sec_from_first(functioning_c_2, functioning_c_1);
        for (auto node_id:functioning_c_2){
            remove_node_from_network(network2, node_id);
        }
        functioning_c_2 = get_functional(network2, node_in_cluster, reinforced);

        if (old_shape1 == functioning_c_1.size() && old_shape2 == functioning_c_2.size()) break;

        old_shape1 = functioning_c_1.size();
        old_shape2 = functioning_c_2.size();
    }

    return functioning_c_1;
}

/**
 * return the functioning component. (in case the network WAS build before calling the function)
 * differance:
 * @param network1 is &network1, not network1
 * @param network2
 * @param node_in_cluster
 * @param reinforced
 * @return
 */
set<int> conjunction_functional(nNetwork &network1, nNetwork &network2, int node_in_cluster, const vector<int>& reinforced){
    set<int> functioning_c_1 = get_functional(network1, node_in_cluster, reinforced);
    set<int> functioning_c_2 = get_functional(network2, node_in_cluster, reinforced);
    set<int> nodes_to_remove;
    int old_shape1 = functioning_c_1.size(),old_shape2 = functioning_c_2.size();

    while(true) {
        subtract_sec_from_first(functioning_c_1, functioning_c_2); // remove nodes in A and not in B(from A)
        for (auto node_id:functioning_c_1){
            remove_node_from_network(network1, node_id);
        }
        functioning_c_1 = get_functional(network1, node_in_cluster, reinforced);

        subtract_sec_from_first(functioning_c_2, functioning_c_1);
        for (auto node_id:functioning_c_2){
            remove_node_from_network(network2, node_id);
        }
        functioning_c_2 = get_functional(network2, node_in_cluster, reinforced);

        if (old_shape1 == functioning_c_1.size() && old_shape2 == functioning_c_2.size()) break;

        old_shape1 = functioning_c_1.size();
        old_shape2 = functioning_c_2.size();
    }

    return functioning_c_1;
}

vector<int> conjunction_functional_translator(yNetwork &network1, yNetwork &network2, int node_in_cluster, const vector<bool>& reinforced){
    return convertSet2Veclvalue(conjunction_functional(convertYaelNW2NerNW(network1), convertYaelNW2NerNW(network2), node_in_cluster,
                                  convert_bool_vec_2_indicies_vec(reinforced)));
}
