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

#include "main/avikodak/sites/geeksforgeeks/graph/page04/gdfs.h"
#include "main/avikodak/sites/geeksforgeeks/graph/page04/gbfs.h"
#include "main/avikodak/sites/geeksforgeeks/graph/page04/pathbetweenvertices.h"
#include "main/avikodak/sites/geeksforgeeks/graph/page04/detectcycledirected.h"
#include "main/avikodak/sites/geeksforgeeks/graph/page04/floydwarshallalgotrithm.h"

#include "main/avikodak/sites/geeksforgeeks/graph/page03/transitiveclosureofgraph.h"

#include "main/avikodak/sites/geeksforgeeks/dp/page01/catalannumbers.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page01/maxproductcutting.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page01/countpathstopleftbottomright.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page01/countwalks.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page01/decodingsdigitsequence.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page01/shortestpathdirectedkedges.h"


#include "main/avikodak/sites/geeksforgeeks/dp/page04/kadanealgo.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/uglynumbers.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/maxsizesubmatrixones.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/fibonnacinumbers.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/longestincreasingsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/longestcommonsubsequence.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/editdistance.h"
#include "main/avikodak/sites/geeksforgeeks/dp/page04/mincostpath.h"

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<vector<int> > costMatrix = getVectorForMatrixUserInput();
	printf("%d",minCostPath(costMatrix,0,0));
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
	graphutil *utils = new graphutil();
	vector<wEdge *> edgeList = utils->getWEdgeList(false);
	int noOfVertices,sourceVertex,destinationVertex;
	scanf("%d %d %d",&noOfVertices,&sourceVertex,&destinationVertex);
	printf("%d",shortestDistanceFloydWarshall(edgeList,noOfVertices,sourceVertex,destinationVertex));//4 0 1 5 1 2 3 2 3 1 0 3 10 4 0 3
}

int main() {
	PRINT_NEW_LINE;
	arrayTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

