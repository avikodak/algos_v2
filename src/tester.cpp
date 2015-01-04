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
#include <algorithm/ds/graphds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/mathds.h>
#include <algorithm/ds/treeds.h>
#include <algorithm/utils/arrayutil.h>
#include <algorithm/utils/avltreeutil.h>
#include <algorithm/utils/bplustreeutil.h>
#include <algorithm/utils/btreeutil.h>
#include <algorithm/utils/commonutil.h>
#include <algorithm/utils/dillutil.h>
#include <algorithm/utils/graphutil.h>
#include <algorithm/utils/mathutil.h>
#include <algorithm/utils/redblacktreeutil.h>
#include <algorithm/utils/sillutil.h>
#include <algorithm/utils/trieutil.h>
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/* 															Testing Includes																	    */
/****************************************************************************************************************************************************/
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/differencebetweenindexes.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findifarrayissubset.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/mindistancenumbers.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/printmatrixinspiralorder.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findrepeatingmissing.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/booleanmatrix.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/fixedpoint.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/countsmallerrightside.h" // Should be updated
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/maxlengthbitonicsubarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/maxvalincdecarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/minimumNumberJumps.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/findsubarraywithsum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/largestsubarray0s1s.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/longestbitonicsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/longestincsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/maximumsumincreasingsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/tripletforsum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/twooddoccurence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/sortedsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/pairforgivendifference.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/smallestpositivemissing.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/maximumproductsubarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/implementtwostacksarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/partitionproblem.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page06/replaceeveryelementwithgreatest.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/maxlenchainofpairs.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/fourelementsforsum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/fourelementsforsumon2logn.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/sortnearlysortedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/maxcircularsubarraysum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/findrowmax1s.h" //To be tested
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/counttriangles.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/iterativequicksort.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/shufflearray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/numberofislands.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page06/printuniquerows.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page05/countingsort.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/dacmaxsubarraysum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/longestincreasingsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/maximumrepeatingnumber.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/mergeoverlappinginterval.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/pancakesorting.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/rearrangepositvenegativeon.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page05/tugofwar.h"

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<vector<bool> > userInput = getBVectorForMatrixUserInput();
	printf("%d",numberOfIslands(userInput));
}

void p(inrNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d -> %d\n",ptr->value,ptr->nextRight != null?ptr->nextRight->value:0);
	p(ptr->left);
	p(ptr->right);
}

void s(isuccesssorNode *ptr){
	if(ptr == null){
		return;
	}
	printf("%d -> %d\n",ptr->value,ptr->successor == null ?0:ptr->successor->value);
	s(ptr->left);
	s(ptr->right);
}

void treeTester(){
	//treeutils *utils = new treeutils();
	//vector<int> userInput = getVectorForUserInput();
	//hash_map<unsigned int,int> indexValueMap = getUserInputForIndexValueMap();
	//	itNode *root = utils->getITreeFromVector(generateISequenceVector(7));
}

void avlTreeTester(){
	//avlutils *utils = new avlutils();
	vector<int> sequence = generateISequenceVector(10);
	PRINT_NEW_LINE;

}

void twoFourTreeTester(){
	vector<int> sequence = generateISequenceVector(30);
	twofourtreeutils *utils = new twofourtreeutils();
	i24Node *root = utils->getTwoFourTreeFromVector(sequence);
	//utils->insertIntoTwoFourTree(&root,12);
	utils->inorderTraversal(root);
}

void sillTester(){
	sillutils *utils = new sillutils();
	sillNode *head = utils->getRandomSill(10,1,50);
	utils->printSill(head);
}

void customTester(){
	char inputSequence[4];
	scanf("%s",inputSequence);
}

void redblackTreeTester(){
	rbutils *utils = new rbutils();
	vector<int> sequence = generateISequenceVector(10);
	iRbTreeNode *root = utils->getRbTreeFromVector(sequence);
	utils->inorderTraversal(root);
	PRINT_NEW_LINE;
	for(unsigned int counter = 1;counter <= 10;counter++){
		sequence.push_back(counter);
	}
	ifRbTreeNode *root2 = utils->getFRbTreeFromVector(sequence);
	utils->inorderTraversal(root2);
	PRINT_NEW_LINE;
	printf("%d %d",utils->height(root),utils->height(root2));
}

void trieTester(){

}

void stringTester(){
	//char userInput[] = "BBABCBCAB";
	//scanf("%s",userInput);
	//reverseWordsInString(userInput);
}

void graphTester(){
	/*vector<vector<int> > adjacencyList = getAdjacencyListForDirectedGraph();
	printf("%d\n",checkForPath(adjacencyList,1,3));//5 7 0 1 0 2 2 1 1 3 2 3 2 4 3 4
	printf("%d",checkForPath(adjacencyList,3,1));//4 6 0 1 0 2 1 2 2 0 2 3 3 3*/
}

int main() {
	PRINT_NEW_LINE;
	arrayTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

