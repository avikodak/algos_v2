/****************************************************************************************************************************************************
 *  File Name   		: tester.cpp 
 *	File Location		: D:\algos\algos_v2\src\tester.cpp
 *  Created on			: Oct 9, 2014 :: 12:55:16 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/


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
/* 															Testing Includes																	    */
/****************************************************************************************************************************************************/
#include "main/avikodak/sites/geeksforgeeks/trees/page10/treetraversals.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page10/sizeoftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page10/aretreesidentical.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/heightoftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/deletetree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/mirrortree.h"

#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/getnthnodesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/printmiddlesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/deleteanodegivenptr.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/deletesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/frequencysill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/getnthnodefromendsill.h"
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

void treeTester(){
	treeutils *utils = new treeutils();
	vector<int> sequence = generateISequenceVector(10);
	itNode *root = utils->getITreeFromVector(sequence);
	deleteLevelON2(&root);
	utils->preOrderTraversal(root);
}

void sillTester(){
	sillutils *utils = new sillutils();
	vector<int> userInput = getVectorForUserInput();
	sillNode *head = utils->getSillFromVector(userInput);
	utils->printSill(head);
	PRINT_NEW_LINE;
	int temp;
	scanf("%d",&temp);
	printf("%d",frequencyOfIntBST(head,temp));
}

int main() {
	PRINT_NEW_LINE;
	sillTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

