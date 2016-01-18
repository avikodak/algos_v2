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

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef LIBV2_UTILS_TREEUTIL_H_
#define LIBV2_UTILS_TREEUTIL_H_

class treeutils{
private:
public:
	itNode *getTree(vector<int> userInput,unsigned int index = 0){
		if(userInput.size() == 0 || index >= userInput.size()){
			return null;
		}
		itNode *root = new itNode(userInput[index]);
		root->left = getTree(userInput,2*index+1);
		root->right = getTree(userInput,2*index+2);
		return root;
	}

	vector<int> getPreOrderValues(itNode *ptr){
		vector<int> preOrderValues;
		if(ptr == null){
			return preOrderValues;
		}
		stack<itNode *> auxSpace;
		itNode *currentNode;
		auxSpace.push(ptr);
		while(!auxSpace.empty()){
			currentNode = auxSpace.top();
			auxSpace.pop();
			preOrderValues.push_back(currentNode->value);
			if(currentNode->right != null){
				auxSpace.push(currentNode->right);
			}
			if(currentNode->left != null){
				auxSpace.push(currentNode->left);
			}
		}
		return preOrderValues;
	}

	vector<int> getInOrderValues(itNode *ptr){
		vector<int> inOrderValues;
		if(ptr == null){
			return inOrderValues;
		}
		stack<itNode *> auxSpace;
		itNode *currentNode = ptr;
		while(!auxSpace.empty() || currentNode != null){
			if(currentNode != null){
				auxSpace.push(currentNode);
				currentNode = currentNode->left;
			}else{
				currentNode = auxSpace.top();
				auxSpace.pop();
				inOrderValues.push_back(currentNode->value);
				currentNode = currentNode->right;
			}
		}
		return inOrderValues;
	}

	vector<int> getPostOrderValues(itNode *ptr){
		vector<int> postOrderValues;
		if(ptr == null){
			return postOrderValues;
		}
		stack<itNode *> auxSpace;
		itNode *currentNode = ptr;
		while(!auxSpace.empty() || currentNode != null){
			if(currentNode != null){
				if(currentNode->right != null){
					auxSpace.push(currentNode->right);
				}
				auxSpace.push(currentNode);
				currentNode = currentNode->left;
			}else{
				currentNode = auxSpace.top();
				auxSpace.pop();
				if(!auxSpace.empty() && currentNode->right == auxSpace.top()){
					auxSpace.pop();
					auxSpace.push(currentNode);
					currentNode = currentNode->right;
				}else{
					postOrderValues.push_back(currentNode->value);
					currentNode = null;
				}
			}
		}
		return postOrderValues;
	}

	vector<itNode *> getPreOrderNodes(itNode *ptr){
		vector<itNode *> preOrderNodes;
		if(ptr == null){
			return preOrderNodes;
		}
		itNode *currentNode = ptr,*temp;
		while(currentNode != null){
			if(currentNode->left != null){
				temp = currentNode->left;
				while(temp->right != null && temp->right == currentNode){
					temp = temp->right;
				}
				if(temp->right == null){
					preOrderNodes.push_back(currentNode);
					temp->right = currentNode;
					currentNode = currentNode->left;
				}else{
					temp->right = null;
					currentNode = currentNode->right;
				}
			}else{
				preOrderNodes.push_back(currentNode);
				currentNode = currentNode->right;
			}
		}
		return preOrderNodes;
	}

	vector<itNode *> getInOrderNodes(itNode *ptr){
		vector<itNode *> inOrderNodes;
		if(ptr == null){
			return inOrderNodes;
		}
		stack<itNode *> auxSpace;
		itNode *currentNode = ptr;
		while(!auxSpace.empty() || currentNode != null){
			if(currentNode != null){
				auxSpace.push(currentNode);
				currentNode = currentNode->left;
			}else{
				currentNode = auxSpace.top();
				auxSpace.pop();
				inOrderNodes.push_back(currentNode);
				currentNode = currentNode->right;
			}
		}
		return inOrderNodes;
	}

	vector<itNode *> getPostOrderNodes(itNode *ptr){
		vector<itNode *> postOrderNodes;
		if(ptr == null){
			return postOrderNodes;
		}
		itNode *currentNode = ptr;
		stack<itNode *> auxSpace;
		while(!auxSpace.empty() || currentNode != null){
			while(currentNode != null){
				auxSpace.push(currentNode);
				currentNode = currentNode->left;
			}
			if(!auxSpace.empty() && auxSpace.top()->right == null){
				currentNode = auxSpace.top();
				auxSpace.pop();
				postOrderNodes.push_back(currentNode);
				while(!auxSpace.empty() && auxSpace.top()->right == currentNode){
					currentNode = auxSpace.top();
					postOrderNodes.push_back(currentNode);
					auxSpace.pop();
				}
			}
			currentNode = auxSpace.empty()?null:auxSpace.top()->right;
		}
		return postOrderNodes;
	}
};

#endif /* LIBV2_UTILS_TREEUTIL_H_ */
