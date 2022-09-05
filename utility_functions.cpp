//
// Created by neriy on 01/09/2022.
//

#include "utility_functions.h"
#include "neriya_yael_converter.h"



void remove_node_from_network(nNetwork &network, const int removed_id){
    set<int> memory = network[removed_id]; // is it the same value or not?
    network[removed_id].clear();
    for (auto j: memory) network[j].erase(removed_id);
}
void print_nNW(map<int, set<int>> &n) {
    cout<<"\n\n~~~~~ print nNetwork ~~~~~\n\n";
    vector<int> keys;
    transform(n.begin(), n.end(), back_inserter(keys), RetrieveKey()); // todo understand how it works

    for (auto i:keys){
        cout<<i<< ":";
        for(auto j:n[i]){
            cout<<j<< " ";
        }
        cout<<'\n';
    }

    cout<<"\n\n~~~~~ ENDED ~~~~~\n\n";
}
set<int> get_cluster_of_node_BFS(nNetwork &network, int node_in_cluster){
    set<int> res, visited;
    stack<int> worklist;
    int cur,v_s;

    worklist.push(node_in_cluster);

    while(!worklist.empty()){
        v_s = visited.size();
        cur = worklist.top();
        worklist.pop();
        visited.insert(cur);

        if(v_s == visited.size()) continue;

        res.insert(cur);
        for (auto i:network[cur]) {
            worklist.push(i);
        }
        v_s++;
    }
    return res;
}

/**
 * A) result += clusters of reinforced nodes
 * B) find the giant component
 * C) result += GC
 *
 * @param network
 * @param node_in_cluster
 * @param reinforced a vector of all the reinforced nodes // todo make sure its not a bool n length vector.
 * @return result
 */
set<int> get_functional(nNetwork &network, int node_in_cluster, const vector<int>& reinforced){
    set<int> res, giant_component, current;
    unordered_set<int> visited;
    int max = 0;

    // updates all reinforced nodes and their clusters
    for (auto i:reinforced){
        if(visited.find(i) != visited.end()) continue;
        current = get_cluster_of_node_BFS(network,i);

        visited.insert(current.begin(),current.end());
        res.insert(current.begin(),current.end());
        if(max < current.size()) {max = current.size(); giant_component = current;}      // update max, and giant
    }

    for (const auto& i:network){
        if(visited.find(i.first) != visited.end()) continue;
        current = get_cluster_of_node_BFS(network,i.first);

        res.insert(current.begin(),current.end());
        if(max < current.size()) {max = current.size(); giant_component = current;}      // update max, and giant
    }
    visited.insert(giant_component.begin(), giant_component.end());
    return res;
}

void subtract_sec_from_first(set<int> &a, set<int> &b){
    vector<int> res,temp;
    for (auto item:b)
        a.extract(item);
}



void print_my_set(set<int> s){
    for (auto i:s){
        cout<<i<<" ";
    }
    cout<<'\n';
}

/**
* todo - create another file. convert yeal to neriya and vice versa. so that using code from utility will be by
 * sending call_func_x_(convertYaelNW2NerNW(NW),YtoN_reinforced(reinforced)) and so on.
*/