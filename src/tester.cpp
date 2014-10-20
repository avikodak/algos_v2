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
#include "main/avikodak/sites/geeksforgeeks/trees/page09/checkforchildrensum.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/converttreetochildrensumproperty.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/countleafnodes.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/deletetree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/heightoftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/istreebst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/levelordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/lowestcommonancestorsbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/minimumvaluebst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/mirrortree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/printroottoleafpaths.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/spirallevelordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page09/treetodll.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/inorderwithoutrecursion.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/inorderwithoutrecursionandstack.h"

#include "main/avikodak/sites/geeksforgeeks/recursion/page01/addition.h"

#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/getnthnodesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/printmiddlesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/deleteanodegivenptr.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/deletesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/frequencysill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page05/getnthnodefromendsill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/issillpalindrome.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/reversesill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/reversesillprint.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/insertintosortedsill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/detectloopsill.h"
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page04/intersectionofsill.h"

#include "main/avikodak/tuts/nptel/dsalgo/lecture01/getmaxelement.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/insertionsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/prefixaverages.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/arraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicarraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/doublingstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/tightstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicstack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicset.h"
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<int> randomVector = generateIRandomVector(10,1,10);
	printIVector(randomVector);
	dynamicset *temp = new dynamicset();
	for(unsigned int counter = 0;counter < randomVector.size();counter++){
		temp->insert(randomVector[counter]);
	}
	temp->printSet();
	temp->deleteVal(7);
	PRINT_NEW_LINE;
	temp->printSet();
}


void treeTester(){
	treeutils *utils = new treeutils();
	itNode *root = utils->getRandomTree(10,1,50);
	imorrisInorderTraversal(root);
}

void sillTester(){
	sillutils *utils = new sillutils();
	sillNode *head = utils->getRandomSill(10,1,50);
	sillNode *head2 = utils->getRandomSill(4,100,200);
	sillNode *temp = head2,*temp1 = head;
	temp1 = temp1->next->next->next;
	while(temp->next != null){
		temp = temp->next;
	}
	temp->next = temp1;
	utils->printSill(head);
	PRINT_NEW_LINE;
	utils->printSill(head2);
	printf("\n%d\t",getIntersectionOfSillLength(head,head2)->value);
	//getIntersectionOfSillLength(head,head2);

}


int main() {
	PRINT_NEW_LINE;
	treeTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

