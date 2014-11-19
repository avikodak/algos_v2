/****************************************************************************************************************************************************
 *  File Name   		: avltreeutil.h 
 *	File Location		: D:\algos\algos_v2\src\lib\utils\avltreeutil.h
 *  Created on			: Oct 9, 2014 :: 12:37:42 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef AVLTREEUTIL_H_
#define AVLTREEUTIL_H_

class avlutils {
private:
	void rotateNodes(ipAvlNode *parent,ipAvlNode *child){
		ipAvlNode *grandParent = parent->parent;
		child->parent = grandParent;
		if(grandParent != null){
			if(grandParent->left == parent){
				grandParent->left = child;
			}else{
				grandParent->right = child;
			}
		}
		parent->parent = child;
		if(parent->left == child){
			parent->left = child->right;
			child->right = parent;
		}else{
			parent->right = child->left;
			child->left = parent;
		}
	}

	void rotateNodes(ifpAvlNode *parent,ifpAvlNode *child){
		ifpAvlNode *grandParent = parent->parent;
		child->parent = grandParent;
		if(grandParent != null){
			if(grandParent->left == parent){
				grandParent->left = child;
			}else{
				grandParent->right = child;
			}
		}
		parent->parent = child;
		if(parent->left == child){
			parent->left = child->right;
			child->right = parent;
		}else{
			parent->right = child->left;
			child->left = parent;
		}
	}

	ipAvlNode *insertAtRightPlaceInAvlTree(ipAvlNode **root,ipAvlNode *currentNode,int value){
		if(*root == null){
			(*root) = new ipAvlNode(value);
			return null;
		}else if(currentNode->value == value){
			return null;
		}else if(currentNode->value > value){
			if(currentNode->left == null){
				currentNode->left = new ipAvlNode(value);
				currentNode->left->parent = currentNode->left;
				return currentNode->left;
			}else{
				return insertAtRightPlaceInAvlTree(root,currentNode->left,value);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new ipAvlNode(value);
				currentNode->right->parent = currentNode->right;
				return currentNode->right;
			}else{
				return insertAtRightPlaceInAvlTree(root,currentNode->right,value);
			}
		}
	}

	ifpAvlNode *insertAtRightPlaceInAvlTree(ifpAvlNode **root,ifpAvlNode *currentNode,int value){
		if(*root == null){
			(*root) = new ifpAvlNode(value);
			return null;
		}
		if(currentNode->value == value){
			currentNode->frequency += 1;
			return null;
		}else if(currentNode->value > value){
			if(currentNode->left == null){
				currentNode->left = new ifpAvlNode(value);
				currentNode->left->parent = currentNode;
				return currentNode->left;
			}else{
				return insertAtRightPlaceInAvlTree(root,currentNode->left,value);
			}
		}else{
			if(currentNode->right == null){
				currentNode->right = new ifpAvlNode(value);
				currentNode->right->parent = currentNode;
				return currentNode->right;
			}else{
				return insertAtRightPlaceInAvlTree(root,currentNode->right,value);
			}
		}
	}

	ipAvlNode *deleteValueAndGetParent(ipAvlNode **root,int value){

	}
public:
	void insertIntoAvlTree(ipAvlNode **root,int value){
		ipAvlNode *parentToInsertedNode = insertAtRightPlaceInAvlTree(root,*root,value);
		if(parentToInsertedNode == null){
			return;
		}
		ipAvlNode *x,*y,*z = parentToInsertedNode;
		unsigned int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight-rightHeight) > 1){
				y = z->value > value?z->left:z->right;
				x = y->value > value?y->left:y->right;
				if((z->left == y && y->left == x)||(z->right == y && y->right == x)){
					if(z->parent == null){
						(*root) = y;
					}
					rotateNodes(z,y);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				}else{
					if(z->parent == null){
						(*root) = x;
					}
					rotateNodes(y,x);
					rotateNodes(z,x);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
					x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
				}
				return;
			}
			z->height = 1 + max(leftHeight,rightHeight);
			z = z->parent;
		}
	}

	void deleteFromAvlTree(ipAvlNode **root,int value){
		ipAvlNode *parentOfDeletedNode = deleteValueAndGetParent(root,value);
		if(parentOfDeletedNode == null){
			return;
		}
		ipAvlNode *z = parentOfDeletedNode,*y,*x;
		unsigned int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight - rightHeight) > 1){
				y = z->left == null?z->right:z->right == null?z->left:z->left->height > z->right->height?z->left:z->right;
				x = y->left == null?y->right:y->right == null?y->left:z->left->height > z->right->height?y->left:y->right;
				if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
					rotateNodes(z,y);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				}else{
					rotateNodes(y,x);
					rotateNodes(z,x);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
					x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
				}
				z  = z->parent;
				continue;
			}
			z->height = 1 + max(leftHeight,rightHeight);
			z = z->parent;
		}
	}

	void insertIntoAvlTree(ifpAvlNode **root,int userInput){
		ifpAvlNode *currentNode = insertAtRightPlaceInAvlTree(root,*root,userInput);
		if(currentNode == null){
			return;
		}
		ifpAvlNode *z = currentNode,*y,*x;
		unsigned int leftHeight,rightHeight;
		while(z != null){
			leftHeight = z->left == null?0:z->left->height;
			rightHeight = z->right == null?0:z->right->height;
			if(abs(leftHeight - rightHeight) > 1){
				y = z->value > userInput?z->left:z->right;
				x = y->value > userInput?y->left:y->right;
				if((z->left == y && y->left == x) || (z->right == y && y->right == x)){
					if(z->parent == null){
						(*root) = y;
					}
					rotateNodes(z,y);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
				}else{
					if(z->parent == null){
						(*root) = x;
					}
					rotateNodes(y,x);
					rotateNodes(z,x);
					z->height = 1 + max(z->left == null?0:z->left->height,z->right == null?0:z->right->height);
					y->height = 1 + max(y->left == null?0:y->left->height,y->right == null?0:y->right->height);
					x->height = 1 + max(x->left == null?0:x->left->height,x->right == null?0:x->right->height);
				}
				return;
			}
			z->height = 1 + max(leftHeight,rightHeight);
			z = z->parent;
		}
	}

	ipAvlNode *getAvlTreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		ipAvlNode *root = null;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			insertIntoAvlTree(&root,userInput[counter]);
		}
		return root;
	}

	ifpAvlNode *getFAvlTreeFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		ifpAvlNode *root = null;
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			insertIntoAvlTree(&root,userInput[counter]);
		}
		return root;
	}

	ipAvlNode *minAvlTree(ipAvlNode *ptr){
		if(ptr == null){
			return null;
		}
		if(ptr->left == null){
			return ptr;
		}
		return minAvlTree(ptr->left);
	}

	ifpAvlNode *minAvlTree(ifpAvlNode *ptr){
		if(ptr == null){
			return null;
		}
		if(ptr->left == null){
			return ptr;
		}
		return minAvlTree(ptr->left);
	}

	ipAvlNode *maxAvlTree(ipAvlNode *ptr){
		if(ptr == null){
			return null;
		}
		if(ptr->right == null){
			return ptr;
		}
		return maxAvlTree(ptr->right);
	}

	ifpAvlNode *maxAvlTree(ifpAvlNode *ptr){
		if(ptr == null){
			return null;
		}
		if(ptr->right == null){
			return ptr;
		}
		return maxAvlTree(ptr->right);
	}

	ipAvlNode *search(ipAvlNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			return ptr;
		}
		if(ptr->value > value){
			return search(ptr->left,value);
		}else{
			return search(ptr->right,value);
		}
	}

	ifpAvlNode *search(ifpAvlNode *ptr,int value){
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			return ptr;
		}else if(ptr->value > value){
			return search(ptr->left,value);
		}else{
			return search(ptr->right,value);
		}
	}

	ipAvlNode *successor(ipAvlNode *ptr,int value){
		static bool keyFound = false;
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			if(ptr->right != null){
				ptr = ptr->right;
				while(ptr->left != null){
					ptr = ptr->left;
				}
				return ptr;
			}
			keyFound = true;
			return null;
		}else if(ptr->value > value){
			ipAvlNode *result = successor(ptr->left,value);
			if(result == null && keyFound){
				return ptr;
			}
			return result;
		}else{
			return successor(ptr->right,value);
		}
	}

	ifpAvlNode *successor(ifpAvlNode *ptr,int value){
		static bool keyFound = false;
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			if(ptr->right == null){
				ptr = ptr->right;
				while(ptr->left != null){
					ptr = ptr->left;
				}
				return ptr;
			}
			keyFound = true;
			return ptr;
		}else if(ptr->value > value){
			ifpAvlNode *result = successor(ptr->left,value);
			if(result == null & keyFound){
				return ptr;
			}
			return result;
		}else{
			return successor(ptr->right,value);
		}
	}

	ipAvlNode *predecessor(ipAvlNode *ptr,int value){
		static bool keyFound = false;
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			if(ptr->left != null){
				ptr = ptr->left;
				while(ptr->right != null){
					ptr = ptr->right;
				}
				return ptr;
			}
			keyFound = true;
			return null;
		}else if(ptr->value > value){
			return predecessor(ptr->left,value);
		}else{
			ipAvlNode *result = predecessor(ptr->right,value);
			if(result == null && keyFound){
				return ptr;
			}
			return result;
		}
	}

	ifpAvlNode *predecessor(ifpAvlNode *ptr,int value){
		static bool keyFound = false;
		if(ptr == null){
			return null;
		}
		if(ptr->value == value){
			if(ptr->right != null){
				ptr = ptr->right;
				while(ptr->left != null){
					ptr = ptr->left;
				}
				return ptr;
			}
			keyFound = true;
			return null;
		}else if(ptr->value > value){
			return predecessor(ptr->left,value);
		}else{
			ifpAvlNode *result = predecessor(ptr->right,value);
			if(result == null && keyFound){
				return ptr;
			}
			return result;
		}
	}
};

#endif /* AVLTREEUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
