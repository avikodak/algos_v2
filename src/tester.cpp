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
using namespace std;

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
#include "main/avikodak/sites/geeksforgeeks/trees/page01/serializedeserializetree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/bottomview.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/topview.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/diagonalsum.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/printnodesbetweenlevels.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/closestleaf.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page01/specificlevelorder.h"

#include "main/avikodak/sites/hackerrank/warmup/loveletter.h"
#include "main/avikodak/sites/hackerrank/warmup/alternatingchar.h"


#include "main/avikodak/sites/codeforces/waytoolongwords.h"
#include "main/avikodak/sites/codeforces/stringtask.h"
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<int> userInput = generateIRandomVector(10,0,10);
	printIVector(userInput);
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
	treeutils *utils = new treeutils();
	itNode *root = utils->getITreeFromVector(generateISequenceVector(31));
	perfectTreeSpecificLevelOrder(root);//8 1 20 2 8 3 22 4 5 5 3 7 25 10 10 11 14 //10 1 1 2 2 3 3 6 4 7 5 12 6 15 7 24 8 25 9 30 10
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
	char userInput[101];
	/*int testCases;
	scanf("%d",&testCases);
	while(testCases--){*/
		scanf("%s",userInput);
		stringTask(userInput);
	/*}*/
}

void graphTester(){
	graphutil *utils = new graphutil();
	vector<wEdge *> edgeList = utils->getWEdgeList(false);
	int noOfVertices,sourceVertex,destinationVertex;
	scanf("%d %d %d",&noOfVertices,&sourceVertex,&destinationVertex);

}

int main() {
	char userInput[101];
	scanf("%s",userInput);
	stringTask(userInput);
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

