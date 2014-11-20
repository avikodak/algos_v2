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
#include <algorithm/utils/trieutil.h>
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
#include "main/avikodak/sites/geeksforgeeks/trees/page08/diameteroftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/doubletree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/foldabletrees.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/inorderwithoutrecursion.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/inorderwithoutrecursionandstack.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/inordersuccessorbst.h" // NOT TESTED
#include "main/avikodak/sites/geeksforgeeks/trees/page08/istreeheightbalanced.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/maximumwidth.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/printnodesatkdistance.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/roottoleafsum.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/sortedbstarray.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page08/treefrompreinorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/checkiftreeissumtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/checkiftreesubtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/connectnodesatsamelevel.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/converttreetosumtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/kthsmallestbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/levelofnode.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/printancestors.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/sortedarraybst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/printbstkeysinrange.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/populateinordersuccessor.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/binarytreetobst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/boundaryoftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/checkinternalnodehasexactlyonechild.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/constructtreefromprepostspecial.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/gettreefromspecialinorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/istreecomplete.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/largestbstsubtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/maxleaftorootsum.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/mergetwobsts.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/printmergedbsts.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/treefromspecialpreorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/verticalsumtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/iterativepostordertwostacks.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/iterativepreordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/morrispreorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/postoredertraversaliterative.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/reverseinordertraversal.h"

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
#include "main/avikodak/sites/geeksforgeeks/linkedlists/page03/mergesort.h"

#include "main/avikodak/tuts/nptel/dsalgo/lecture01/getmaxelement.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/insertionsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/prefixaverages.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/arraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicarraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/doublingstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/tightstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicstack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicset.h"

#include "main/avikodak/tuts/saurabhacademy/cuttingrod.h"
#include "main/avikodak/tuts/saurabhacademy/coinchange.h"
#include "main/avikodak/tuts/saurabhacademy/generatesets.h"
#include "main/avikodak/tuts/saurabhacademy/permutation.h"
#include "main/avikodak/tuts/saurabhacademy/longestincreasingsubsequence.h"
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<int> sequence = getVectorForUserInput();
	printf("%d\n",longestIncreasingSubSequenceMemoization(sequence,8));
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
	//vector<int> sequence = getVectorForUserInput();
	//itNode *root = utils->getITreeFromVector(sequence);
	hash_map<unsigned int,int> indexNodeMap = getUserInputForIndexValueMap();
	itNode *root = utils->getITreeFromHashmap(indexNodeMap);
	printf("%d\t",isTreeFoldable(root));
}

void avlTreeTester(){
	avlutils *utils = new avlutils();
	vector<int> sequence = generateISequenceVector(10);
	for(unsigned int counter = 1;counter <= 10;counter++){
		sequence.push_back(counter);
	}
	ifpAvlNode *root = utils->getFAvlTreeFromVector(sequence);
	//utils->insertIntoAvlTree(&root,1);
	utils->inorderTraversal(root);
	PRINT_NEW_LINE;
	printf("%d\n",utils->getHeightOfTree(root));
	printf("%d\n",utils->minAvlTree(root)->value);
	printf("%d\n",utils->maxAvlTree(root)->value);
	ifpAvlNode *temp1,*temp2;
	for(unsigned int counter = 1;counter <= 10;counter++){
		printf("%d \t %d\t",(temp1 = utils->predecessor(root,counter)) == null?INT_MIN:temp1->value,(temp2 = utils->successor(root,counter))==null?INT_MAX:temp2->value);
		PRINT_NEW_LINE;
	}
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
	mergeSort(&head);
	utils->printSill(head);
}

void customTester(){
	char inputSequence[4];
	scanf("%s",inputSequence);
	printPermutation(inputSequence,0,3);
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

int main() {
	PRINT_NEW_LINE;
	treeTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

