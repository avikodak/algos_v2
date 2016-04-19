/****************************************************************************************************************************************************
 *  File Name                   : treeutil.h
 *  File Location               : /algos_v2/src/libv2/utils/treeutil.h
 *  Created on                  : Jan 16, 2016 :: 10:59:00 PM
 *  Author                      : avikodak
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <stdint.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/commonutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_UTILS_TREEUTIL_H_
#define LIBV2_UTILS_TREEUTIL_H_

class treeutils {
private:
    vector<int> getRandomVector(unsigned int size,int lowerLimit,int upperLimit) {
        return getIRandomVector(size,lowerLimit,upperLimit);
    }
public:
    itNode *getTree(vector<int> userInput,unsigned int index = 0) {
        if(userInput.size() == 0 || index >= userInput.size()) {
            return null;
        }
        itNode *root = new itNode(userInput[index]);
        root->left = getTree(userInput,2*index+1);
        root->right = getTree(userInput,2*index+2);
        return root;
    }

    inrNode *getINRTree(vector<int> userInput,unsigned int index = 0) {
        if(userInput.size() == 0 || index >= userInput.size()) {
            return null;
        }
        inrNode *root = new inrNode(userInput[index]);
        root->left = getINRTree(userInput,2*index+1);
        root->right = getINRTree(userInput,2*index+2);
        return root;
    }

    itNode *getTree(map<unsigned int,int> userInput,unsigned int index = 0) {
        static bool isZeroStartIndex = index?true:false;
        if(userInput.find(index) == userInput.end()) {
            return null;
        }
        itNode *root = new itNode(userInput[index]);
        root->left = getTree(userInput,isZeroStartIndex?2*index+1:2*index+2);
        root->right = getTree(userInput,isZeroStartIndex?2*index:2*index+1);
        return root;
    }

    itNode *getRandomITree(unsigned int size,int lowerLimit = 0,int upperLimit = INT_MAX) {
        return getTree(this->getRandomVector(size,lowerLimit,upperLimit));
    }

    itNode *getINRRandomTree(unsigned int size,int lowerLimit = 0,int upperLimit = INT_MAX) {
        return getINRTree(this->getRandomVector(size,lowerLimit,upperLimit));
    }

    unsigned int getSizeOfTree(itNode *ptr) {
        if(ptr == null) {
            return 0;
        }
        return 1 + getSizeOfTree(ptr->left) + getSizeOfTree(ptr->right);
    }

    unsigned int getHeightOfTree(itNode *ptr) {
        if(ptr == null) {
            return 0;
        }
        return 1 + max(getHeightOfTree(ptr->left),getHeightOfTree(ptr->right));
    }

    void preOrderTraversal(itNode *ptr) {
        if(ptr == null) {
            return;
        }
        printf("%d\t",ptr->value);
        preOrderTraversal(ptr->left);
        preOrderTraversal(ptr->right);
    }

    void inOrderTraversal(itNode *ptr) {
        if(ptr == null) {
            return;
        }
        inOrderTraversal(ptr->left);
        printf("%d\t",ptr->value);
        inOrderTraversal(ptr->right);
    }

    void postOrderTraversal(itNode *ptr) {
        if(ptr == null) {
            return;
        }
        postOrderTraversal(ptr->left);
        postOrderTraversal(ptr->right);
        printf("%d\t",ptr->value);
    }

    void levelOrderTraversal(itNode *ptr) {
        if(ptr == null) {
            return;
        }
        queue<itNode *> auxSpace;
        itNode *currentNode;
        auxSpace.push(ptr);
        unsigned int levelSize;
        while(!auxSpace.empty()) {
            levelSize = auxSpace.size();
            while(levelSize--) {
                currentNode = auxSpace.front();
                auxSpace.pop();
                printf("%d\t",currentNode->value);
                if(currentNode->left != null) {
                    auxSpace.push(currentNode->left);
                }
                if(currentNode->right != null) {
                    auxSpace.push(currentNode->right);
                }
            }
            printf("\n");
        }
    }

    vector<int> getPreOrderValues(itNode *ptr) {
        vector<int> preOrderValues;
        if(ptr == null) {
            return preOrderValues;
        }
        stack<itNode *> auxSpace;
        itNode *currentNode;
        auxSpace.push(ptr);
        while(!auxSpace.empty()) {
            currentNode = auxSpace.top();
            auxSpace.pop();
            preOrderValues.push_back(currentNode->value);
            if(currentNode->right != null) {
                auxSpace.push(currentNode->right);
            }
            if(currentNode->left != null) {
                auxSpace.push(currentNode->left);
            }
        }
        return preOrderValues;
    }

    vector<int> getInOrderValues(itNode *ptr) {
        vector<int> inOrderValues;
        if(ptr == null) {
            return inOrderValues;
        }
        stack<itNode *> auxSpace;
        itNode *currentNode = ptr;
        while(!auxSpace.empty() || currentNode != null) {
            if(currentNode != null) {
                auxSpace.push(currentNode);
                currentNode = currentNode->left;
            } else {
                currentNode = auxSpace.top();
                auxSpace.pop();
                inOrderValues.push_back(currentNode->value);
                currentNode = currentNode->right;
            }
        }
        return inOrderValues;
    }

    vector<int> getPostOrderValues(itNode *ptr) {
        vector<int> postOrderValues;
        if(ptr == null) {
            return postOrderValues;
        }
        stack<itNode *> auxSpace;
        itNode *currentNode = ptr;
        while(!auxSpace.empty() || currentNode != null) {
            if(currentNode != null) {
                if(currentNode->right != null) {
                    auxSpace.push(currentNode->right);
                }
                auxSpace.push(currentNode);
                currentNode = currentNode->left;
            } else {
                currentNode = auxSpace.top();
                auxSpace.pop();
                if(!auxSpace.empty() && currentNode->right == auxSpace.top()) {
                    auxSpace.pop();
                    auxSpace.push(currentNode);
                    currentNode = currentNode->right;
                } else {
                    postOrderValues.push_back(currentNode->value);
                    currentNode = null;
                }
            }
        }
        return postOrderValues;
    }

    vector<itNode *> getPreOrderNodes(itNode *ptr) {
        vector<itNode *> preOrderNodes;
        if(ptr == null) {
            return preOrderNodes;
        }
        itNode *currentNode = ptr,*temp;
        while(currentNode != null) {
            if(currentNode->left != null) {
                temp = currentNode->left;
                while(temp->right != null && temp->right == currentNode) {
                    temp = temp->right;
                }
                if(temp->right == null) {
                    preOrderNodes.push_back(currentNode);
                    temp->right = currentNode;
                    currentNode = currentNode->left;
                } else {
                    temp->right = null;
                    currentNode = currentNode->right;
                }
            } else {
                preOrderNodes.push_back(currentNode);
                currentNode = currentNode->right;
            }
        }
        return preOrderNodes;
    }

    vector<itNode *> getInOrderNodes(itNode *ptr) {
        vector<itNode *> inOrderNodes;
        if(ptr == null) {
            return inOrderNodes;
        }
        stack<itNode *> auxSpace;
        itNode *currentNode = ptr;
        while(!auxSpace.empty() || currentNode != null) {
            if(currentNode != null) {
                auxSpace.push(currentNode);
                currentNode = currentNode->left;
            } else {
                currentNode = auxSpace.top();
                auxSpace.pop();
                inOrderNodes.push_back(currentNode);
                currentNode = currentNode->right;
            }
        }
        return inOrderNodes;
    }

    vector<itNode *> getPostOrderNodes(itNode *ptr) {
        vector<itNode *> postOrderNodes;
        if(ptr == null) {
            return postOrderNodes;
        }
        itNode *currentNode = ptr;
        stack<itNode *> auxSpace;
        while(!auxSpace.empty() || currentNode != null) {
            while(currentNode != null) {
                auxSpace.push(currentNode);
                currentNode = currentNode->left;
            }
            if(!auxSpace.empty() && auxSpace.top()->right == null) {
                currentNode = auxSpace.top();
                auxSpace.pop();
                postOrderNodes.push_back(currentNode);
                while(!auxSpace.empty() && auxSpace.top()->right == currentNode) {
                    currentNode = auxSpace.top();
                    postOrderNodes.push_back(currentNode);
                    auxSpace.pop();
                }
            }
            currentNode = auxSpace.empty()?null:auxSpace.top()->right;
        }
        return postOrderNodes;
    }

    itHashMap *getTreeInHashMap(itNode *ptr,bool startIndexAtZero = true) {
        if(ptr == null) {
            return null;
        }
        hash_map<unsigned int,itNode *> indexNodeMap;
        hash_map<intptr_t,unsigned int> nodeIndexMap;
        hash_map<unsigned int,itNode *>::iterator itToIndexNodeMap;
        hash_map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
        indexNodeMap.insert(pair<unsigned int,itNode *>(ptr,startIndexAtZero?0:1));
        nodeIndexMap.insert(pair<intptr_t,unsigned int>(startIndexAtZero?0:1,ptr));
        queue<itNode *> auxSpace;
        auxSpace.push(ptr);
        itNode *currentNode;
        unsigned int currentNodeIndex;
        while(!auxSpace.empty()) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            currentNodeIndex = nodeIndexMap.find((intptr_t)currentNode);
            if(currentNode->left != null) {
                indexNodeMap.insert(pair<unsigned int,itNode *>(startIndexAtZero?2*currentNodeIndex+1:2*currentNodeIndex,currentNode->left));
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,startIndexAtZero?2*currentNodeIndex+1:2*currentNodeIndex));
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                indexNodeMap.insert(pair<unsigned int,itNode *>(startIndexAtZero?2*currentNodeIndex+2:2*currentNodeIndex+1,currentNode->right));
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,startIndexAtZero?2*currentNodeIndex+2:2*currentNodeIndex+1));
                auxSpace.push(currentNode->right);
            }
        }
        return new itHashMap(indexNodeMap,nodeIndexMap);
    }

    itMap *getTreeInMap(itNode *ptr,bool startIndexAtZero = 0) {
        if(ptr == null) {
            return null;
        }
        map<unsigned int,itNode *> indexNodeMap;
        map<intptr_t,unsigned int> nodeIndexMap;
        map<unsigned int,itNode *>::iterator itToIndexNodeMap;
        map<intptr_t,unsigned int>::iterator itToNodeIndexMap;
        indexNodeMap.insert(pair<unsigned int,itNode *>(ptr,startIndexAtZero?0:1));
        nodeIndexMap.insert(pair<intptr_t,unsigned int>(startIndexAtZero?0:1,ptr));
        queue<itNode *> auxSpace;
        auxSpace.push(ptr);
        itNode *currentNode;
        unsigned int currentNodeIndex;
        while(!auxSpace.empty()) {
            currentNode = auxSpace.front();
            auxSpace.pop();
            currentNodeIndex = nodeIndexMap.find((intptr_t)currentNode);
            if(currentNode->left != null) {
                indexNodeMap.insert(pair<unsigned int,itNode *>(startIndexAtZero?2*currentNodeIndex+1:2*currentNodeIndex,currentNode->left));
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->left,startIndexAtZero?2*currentNodeIndex+1:2*currentNodeIndex));
                auxSpace.push(currentNode->left);
            }
            if(currentNode->right != null) {
                indexNodeMap.insert(pair<unsigned int,itNode *>(startIndexAtZero?2*currentNodeIndex+2:2*currentNodeIndex+1,currentNode->right));
                nodeIndexMap.insert(pair<intptr_t,unsigned int>((intptr_t)currentNode->right,startIndexAtZero?2*currentNodeIndex+2:2*currentNodeIndex+1));
                auxSpace.push(currentNode->right);
            }
        }
        return new itMap(indexNodeMap,nodeIndexMap);
    }


};

#endif /* LIBV2_UTILS_TREEUTIL_H_ */
