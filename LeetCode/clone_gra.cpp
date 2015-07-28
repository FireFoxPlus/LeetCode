
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 #include <vector>
 #include <queue>
 #include <iostream>
 #include <map>
 using namespace std;

struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode * , UndirectedGraphNode *> record;
    queue<UndirectedGraphNode *> src;
    //queue<UndirectedGraphNode *> dst;
    if(node == NULL)
        return NULL;
    src.push(node);
    UndirectedGraphNode *head_new = new UndirectedGraphNode(node->label);
    record[node] = head_new;
    while(!src.empty())
    {
        UndirectedGraphNode *srcTmp = src.front();
        src.pop();
        UndirectedGraphNode *dstTmp = record[srcTmp];
        //record.insert(map<UndirectedGraphNode * , UndirectedGraphNode *>::value_type(srcTmp , dstTmp));

        vector<UndirectedGraphNode *>::iterator itr;
        for(itr = (srcTmp->neighbors).begin();
            itr != (srcTmp->neighbors).end();
            itr++)
        {
            if(record.count(*itr) == 0)
            {
                UndirectedGraphNode *new_node = new UndirectedGraphNode((*itr)->label);
                src.push(*itr);
                record.insert(map<UndirectedGraphNode * , UndirectedGraphNode*>::value_type(*itr , new_node));
                dstTmp->neighbors.push_back(new_node);
            }
            else
                dstTmp->neighbors.push_back(record[*itr]);
        }
    }
    return record[node];
    }
};
