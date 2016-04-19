/****************************************************************************************************************************************************
 *  File Name                   : redblacktreeutil.h
 *  File Location               : \algos_v2\src\lib\utils\redblacktreeutil.h
 *  Created on                  : Oct 9, 2014 :: 12:38:08 PM
 *  Author                      : AVINASH
 *  Testing Status              : TODO
 *  URL                         : TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                             */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                             */
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>

/****************************************************************************************************************************************************/
/*                                                             USER DEFINED CONSTANTS                                                                     */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE START                                                                     */
/****************************************************************************************************************************************************/

#ifndef REDBLACKTREEUTIL_H_
#define REDBLACKTREEUTIL_H_

class rbutils {
private:
    //Tested
    void rotateNodes(iRbTreeNode *parent,iRbTreeNode *child) {
        iRbTreeNode *grandParent = parent->parent;
        child->parent = grandParent;
        parent->parent = child;
        if(grandParent != null) {
            if(grandParent->left == parent) {
                grandParent->left = child;
            } else {
                grandParent->right = child;
            }
        }
        if(parent->left == child) {
            parent->left = child->right;
            child->right = parent;
        } else {
            parent->right = child->left;
            child->left = parent;
        }
    }

    void rotateNodes(ifRbTreeNode *parent,ifRbTreeNode *child) {
        ifRbTreeNode *grandParent = parent->parent;
        parent->parent = child;
        child->parent = grandParent;
        if(grandParent != null) {
            if(grandParent->left == parent) {
                grandParent->left = child;
            } else {
                grandParent->right = child;
            }
        }
        if(parent->left == child) {
            parent->left = child->right;
            child->right = parent;
        } else {
            parent->right = child->left;
            child->left = parent;
        }
    }

    //Tested
    iRbTreeNode *insertAtRightPlace(iRbTreeNode **root,iRbTreeNode *currentNode,int value) {
        if(*root == null) {
            (*root) = new iRbTreeNode(value);
            (*root)->isRedNode = false;
            return null;
        }
        if(currentNode->value == value) {
            return null;
        } else if(currentNode->value > value) {
            if(currentNode->left == null) {
                currentNode->left = new iRbTreeNode(value);
                currentNode->left->parent = currentNode;
                return currentNode->left;
            } else {
                return insertAtRightPlace(root,currentNode->left,value);
            }
        } else {
            if(currentNode->right == null) {
                currentNode->right = new iRbTreeNode(value);
                currentNode->right->parent = currentNode;
                return currentNode->right;
            } else {
                return insertAtRightPlace(root,currentNode->right,value);
            }
        }
    }

    //Tested
    void reorganiseRbTreePostInsertion(iRbTreeNode **root,iRbTreeNode *currentNode) {
        if(currentNode->parent == null) {
            if(currentNode->isRedNode) {
                currentNode->isRedNode = false;
            }
            return;
        }
        iRbTreeNode *parent = currentNode->parent;
        if(!parent->isRedNode) {
            return;
        }
        iRbTreeNode *grandParent = parent->parent;
        if(grandParent->left == parent) {
            if(grandParent->right == null || !grandParent->right->isRedNode) {
                if(grandParent->parent == null) {
                    (*root) = parent;
                }
                rotateNodes(grandParent,parent);
                grandParent->isRedNode = true;
                parent->isRedNode = false;
                return;
            } else {
                grandParent->isRedNode = true;
                grandParent->left->isRedNode = false;
                grandParent->right->isRedNode = false;
                if(grandParent->parent == null) {
                    grandParent->isRedNode = false;
                    return;
                }
                reorganiseRbTreePostInsertion(root,grandParent);
            }
        } else {
            if(grandParent->left == null || !grandParent->left->isRedNode) {
                if(grandParent->parent == null) {
                    (*root) = parent;
                }
                rotateNodes(grandParent,parent);
                grandParent->isRedNode = true;
                parent->isRedNode = false;
                return;
            } else {
                grandParent->isRedNode = true;
                grandParent->left->isRedNode = false;
                grandParent->right->isRedNode = false;
                if(grandParent->parent == null) {
                    grandParent->isRedNode = false;
                    return;
                }
                reorganiseRbTreePostInsertion(root,grandParent);
            }
        }
    }

    ifRbTreeNode *insertAtRightPlace(ifRbTreeNode **root,ifRbTreeNode *currentNode,int value) {
        if(*root == null) {
            (*root) = new ifRbTreeNode(value);
            (*root)->isRedNode = false;
            return null;
        }
        if(currentNode->value == value) {
            currentNode->frequency += 1;
            return null;
        }
        if(currentNode->value > value) {
            if(currentNode->left == null) {
                currentNode->left = new ifRbTreeNode(value);
                currentNode->left->parent = currentNode;
                return currentNode->left;
            } else {
                return insertAtRightPlace(root,currentNode->left,value);
            }
        } else {
            if(currentNode->right == null) {
                currentNode->right = new ifRbTreeNode(value);
                currentNode->right->parent = currentNode;
                return currentNode->right;
            } else {
                return insertAtRightPlace(root,currentNode->right,value);
            }
        }
    }

    void reorganiseRbTreePostInsertion(ifRbTreeNode **root,ifRbTreeNode *currentNode) {
        if(currentNode->parent == null) {
            currentNode->parent->isRedNode = false;
            return;
        }
        ifRbTreeNode *parent = currentNode->parent;
        if(!parent->isRedNode) {
            return;
        }
        ifRbTreeNode *grandParent = parent->parent;
        if(grandParent->left == parent) {
            if(grandParent->right == null || !grandParent->right->isRedNode) {
                if(grandParent->parent == null) {
                    (*root) = parent;
                }
                rotateNodes(grandParent,parent);
                grandParent->isRedNode = true;
                parent->isRedNode = false;
                return;
            } else {
                grandParent->isRedNode = true;
                grandParent->left->isRedNode = false;
                grandParent->right->isRedNode = false;
                if(grandParent->parent == null) {
                    grandParent->isRedNode = false;
                    return;
                }
                reorganiseRbTreePostInsertion(root,grandParent);
            }
        } else {
            if(grandParent->left == null || !grandParent->left->isRedNode) {
                if(grandParent->parent == null) {
                    (*root) = parent;
                }
                rotateNodes(grandParent,parent);
                grandParent->isRedNode = true;
                parent->isRedNode = false;
                return;
            } else {
                grandParent->isRedNode = true;
                grandParent->left->isRedNode = false;
                grandParent->right->isRedNode = false;
                if(grandParent->parent == null) {
                    grandParent->isRedNode = false;
                    return;
                }
                reorganiseRbTreePostInsertion(root,grandParent);
            }
        }
    }
public:
    //Tested
    void insert(iRbTreeNode **root,int value) {
        iRbTreeNode *ptrToInsertedNode = insertAtRightPlace(root,*root,value);
        if(ptrToInsertedNode == null) {
            return;
        }
        if(!ptrToInsertedNode->parent->isRedNode) {
            return;
        }
        reorganiseRbTreePostInsertion(root,ptrToInsertedNode);
    }

    void insert(ifRbTreeNode **root,int value) {
        ifRbTreeNode *ptrToInsertedNode = insertAtRightPlace(root,*root,value);
        if(ptrToInsertedNode == null) {
            return;
        }
        if(!ptrToInsertedNode->parent->isRedNode) {
            return;
        }
        reorganiseRbTreePostInsertion(root,ptrToInsertedNode);
    }

    //Tested
    iRbTreeNode *getRbTreeFromVector(vector<int> userInput) {
        if(userInput.size() == 0) {
            return null;
        }
        iRbTreeNode *root = null;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            insert(&root,userInput[counter]);
        }
        return root;
    }

    ifRbTreeNode *getFRbTreeFromVector(vector<int> userInput) {
        if(userInput.size() == 0) {
            return null;
        }
        ifRbTreeNode *root = null;
        for(unsigned int counter = 0; counter < userInput.size(); counter++) {
            insert(&root,userInput[counter]);
        }
        return root;
    }

    //Tested
    void inorderTraversal(iRbTreeNode *ptr) {
        if(ptr == null) {
            return;
        }
        inorderTraversal(ptr->left);
        printf("%d(%c)\t",ptr->value,ptr->isRedNode?'R':'B');
        inorderTraversal(ptr->right);
    }

    void inorderTraversal(ifRbTreeNode *ptr) {
        if(ptr == null) {
            return;
        }
        inorderTraversal(ptr->left);
        printf("%d %d(%c)\t",ptr->value,ptr->frequency,ptr->isRedNode?'R':'B');
        inorderTraversal(ptr->right);
    }

    unsigned int height(iRbTreeNode *ptr) {
        if(ptr == null) {
            return 0;
        }
        return 1 + max(height(ptr->left),height(ptr->right));
    }

    unsigned int height(ifRbTreeNode *ptr) {
        if(ptr == null) {
            return 0;
        }
        return 1 + max(height(ptr->left),height(ptr->right));
    }
};

#endif /* REDBLACKTREEUTIL_H_ */

/****************************************************************************************************************************************************/
/*                                                                 MAIN CODE END                                                                         */
/****************************************************************************************************************************************************/
