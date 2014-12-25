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
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/equilibriumindex.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findduplicates.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findifarrayissubset.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findsmallestmissingnumber.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/frequencysortedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/nextgreaterelement.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page07/booleanmatrix.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/countsmallerrightside.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/findrepeatingmissing.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page05/pancakesorting.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page04/countingsort.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/maximumrepeatingnumber.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/mergeksortedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/printallcombinations.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/productthreesequence.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/sortbyfrequencyavltree.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/positiveinfunction.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/mergeoverlappinginterval.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page04/rearrangepositvenegativeon.h"


#include "main/avikodak/sites/geeksforgeeks/arrays/page03/bucketsort.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/issubarrayforzero.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/kthsortedmatrix.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/moveallzeros.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/numberofzeros.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/pairsfordifference.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/radixsort.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page03/straightradixsort.h"


#include "main/avikodak/sites/geeksforgeeks/strings/page05/maxfreqchar.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page05/removeduplicates.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page05/printduplicates.h"

#include "main/avikodak/sites/geeksforgeeks/strings/page04/reversewordsstring.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page04/runlengthencoding.h"

#include "main/avikodak/sites/geeksforgeeks/dp/page03/longestpalindromicsequence.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/fibonnacinumbers.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/longestincreasingsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/kadanealgo.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/uglynumbers.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/maxsizesubmatrixones.h"


/*
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/findsubarraywithsum.h"
 */


/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<int> userInput = generateIRandomVector(10,0,50);
	pancakeSorting(userInput);
	printIVector(userInput,false);
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
	char userInput[] = "BBABCBCAB";
	//scanf("%s",userInput);
	//reverseWordsInString(userInput);
	printf("%d",longestPalindromicSubSequence(userInput));
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

