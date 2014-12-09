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
/*
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
#include "main/avikodak/sites/geeksforgeeks/trees/page07/insertintoavltree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/kthsmallestbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/levelofnode.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/printancestors.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/sortedarraybst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/printbstkeysinrange.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page07/populateinordersuccessor.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/binarytreetobst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/boundaryoftree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/constructbstfrompreorder.h" // REVISE
#include "main/avikodak/sites/geeksforgeeks/trees/page06/checkinternalnodehasexactlyonechild.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/constructtreefromprepostspecial.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/floorceilbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/gettreefromspecialinorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/istreecomplete.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/largestbstsubtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/maxleaftorootsum.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/mergetwobsts.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/printmergedbsts.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/treefromspecialpreorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/twonodesfixbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page06/verticalsumtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/constructcompletetree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/constructcompletetreefromsill.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/converttospecialbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/iterativepostordertwostacks.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/iterativepreordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/morrispreorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/postoredertraversaliterative.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/reverseinordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/reverselevelordertraversal.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/pairforgivensumbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page05/tripletfrombstforvalue.h" // NOT TESTED
#include "main/avikodak/sites/geeksforgeeks/trees/page04/convertTreeToDllON.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/converttreetodllON2.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/depthofoddleafnode.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/heightiterative.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/printancestorsiterative.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/differencebetweenoddevenlevels.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/treeisomorphism.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page04/printprefrompostinorder.h" // Should be changed


#include "main/avikodak/sites/geeksforgeeks/trees/page03/addgreatervaluesbst.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/checkifallleavesareatsamelevel.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/printleftview.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/sumofnumbersroottoleaf.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/converttreetodllON.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/nextrightnode.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page03/extractleavesasdll.h"

#include "main/avikodak/sites/geeksforgeeks/trees/page02/treefromlevelinorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/verticalorderhashmap.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/printverticalorder.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/printallnodesatkdistance.h" // Check for parent pointer
#include "main/avikodak/sites/geeksforgeeks/trees/page02/lowestancestorstree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/printnodeswithnosibling.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/printrightview.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/reversealternatelevels.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/transformbsttosumtree.h"
#include "main/avikodak/sites/geeksforgeeks/trees/page02/printnodesatkdistancefromleaf.h"

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

#include "main/avikodak/sites/geeksforgeeks/arrays/page11/getpairforgivensum.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page11/majorityelement.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/findmissingnumber.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/largestsumcontigousarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/leadersofarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/mergesortedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/numberoddtimes.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/reversearray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/rotatearray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/rotatearrayreversealgo.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/searchinsortedpivotedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page10/sortbyfrequency.h" // Not tested
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/checkformajorityelement.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/findrepeatingelements.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/floorceiling.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/maxminarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/productarraypuzzle.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/segregate0s1s.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/segregateevenoddnumbers.h"
//#include "main/avikodak/sites/geeksforgeeks/arrays/page09/smallestsecondsmallest.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page09/sortarray0s1s2s.h"
//#include "main/avikodak/sites/geeksforgeeks/arrays/page09/unionintersectionsortedarray.h"
//#include "main/avikodak/sites/geeksforgeeks/arrays/page08/checkarrayisconsecutive.h"
 *
 */
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/equilibriumindex.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findduplicates.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findifarrayissubset.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/findsmallestmissingnumber.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/frequencysortedarray.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page08/nextgreaterelement.h"

#include "main/avikodak/sites/geeksforgeeks/arrays/page07/booleanmatrix.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/countsmallerrightside.h"
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/findrepeatingmissing.h"


#include "main/avikodak/sites/geeksforgeeks/strings/page05/maxfreqchar.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page05/removeduplicates.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page05/printduplicates.h"

#include "main/avikodak/sites/geeksforgeeks/strings/page04/reversewordsstring.h"
#include "main/avikodak/sites/geeksforgeeks/strings/page04/runlengthencoding.h"

/*
#include "main/avikodak/sites/geeksforgeeks/arrays/page07/findsubarraywithsum.h"
 */
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/getmaxelement.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/insertionsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture01/prefixaverages.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/arraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicarraystack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/doublingstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/tightstrategy.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicstack.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/dynamicset.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture02/span.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture03/arrayqueue.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture04/binarysearch.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture04/chaining.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture04/linearsearch.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture06/ttreeutil.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture07/eulertraversal.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture07/inordertraversal.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture07/postordertraversal.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture07/preordertraversal.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture07/treefrompreinorder.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/balancedbstfromsortedvector.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/bst.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/minimumbst.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/maxvalbst.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/predecessor.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/ordereddictionary.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/successor.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/searchinbst.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture08/unordereddictionary.h"  // To Be Tested
#include "main/avikodak/tuts/nptel/dsalgo/lecture09/bstsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture10/quicksort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture10/randomizedquicksort.h" // To Be Tested
#include "main/avikodak/tuts/nptel/dsalgo/lecture22/mergesort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture22/selectionsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture23/bucketsort.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture25/adjacencylist.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture25/adjacencymatrix.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture25/bfs.h"
#include "main/avikodak/tuts/nptel/dsalgo/lecture25/checkforpath.h"
/*
#include "main/avikodak/tuts/saurabhacademy/cuttingrod.h"
#include "main/avikodak/tuts/saurabhacademy/coinchange.h"
#include "main/avikodak/tuts/saurabhacademy/generatesets.h"
#include "main/avikodak/tuts/saurabhacademy/permutation.h"
#include "main/avikodak/tuts/saurabhacademy/longestincreasingsubsequence.h"
 */
/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/
void arrayTester() {
	vector<int> userInput;
	userInput.clear();
	userInput = generateIRandomVector(10,1,50);

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
	char userInput[] = "geeksforgeeks";
	//scanf("%s",userInput);
	//reverseWordsInString(userInput);
	printf("%s",runLengthEncoding(userInput));
}

void graphTester(){
	vector<vector<int> > adjacencyList = getAdjacencyListForDirectedGraph();
	printf("%d\n",checkForPath(adjacencyList,1,3));//5 7 0 1 0 2 2 1 1 3 2 3 2 4 3 4
	printf("%d",checkForPath(adjacencyList,3,1));//4 6 0 1 0 2 1 2 2 0 2 3 3 3
}

int main() {
	PRINT_NEW_LINE;
	graphTester();
	return 0;
}

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/

