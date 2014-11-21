/****************************************************************************************************************************************************
 *  File Name   		: boundaryoftree.h 
 *	File Location		: D:\algos\algos_v2\src\main\avikodak\sites\geeksforgeeks\trees\page06\boundaryoftree.h
 *  Created on			: Oct 31, 2014 :: 8:17:41 PM
 *  Author				: AVINASH
 *  Testing Status 		: Tested
 *  URL 				: http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef BOUNDARYOFTREE_H_
#define BOUNDARYOFTREE_H_

//Tested
void printLeftView(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left != null && ptr->right != null){
		printf("%d\t",ptr->value);
	}
	if(ptr->left != null){
		printLeftView(ptr->left);
	}else if(ptr->right != null){
		printLeftView(ptr->right);
	}
}

//Tested
void printRightView(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->right != null){
		printRightView(ptr->right);
	}else if(ptr->left != null){
		printRightView(ptr->left);
	}
	if(ptr->left != null && ptr->right != null){
		printf("%d\t",ptr->value);
	}
}

//Tested
void printLeaves(itNode *ptr){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		printf("%d\t",ptr->value);
		return;
	}
	printLeaves(ptr->left);
	printLeaves(ptr->right);
}

//Tested
void printBoundary(itNode *ptr){
	if(ptr == null){
		return;
	}
	printLeftView(ptr);
	printLeaves(ptr);
	printRightView(ptr);
}

#endif /* BOUNDARYOFTREE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
