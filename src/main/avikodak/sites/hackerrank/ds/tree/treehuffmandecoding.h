/****************************************************************************************************************************************************
 *  File Name                   : treehuffmandecoding.h
 *  File Location               : D:\projects\cpp\algos_v2\src\main\avikodak\sites\hackerrank\ds\tree\treehuffmandecoding.h
 *  Created on                  : Jul 5, 2015 :: 11:37:51 PM
 *  Author                      : avikodak
 *  Testing Status              : Tested
 *  URL                         : https://www.hackerrank.com/challenges/tree-huffman-decoding
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                         NAMESPACE DECLARATION AND IMPORTS                                                        */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/*                                                                 INCLUDES                                                                         */
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
#include <lib/constants/constants.h>
#include <lib/ds/commonds.h>
#include <lib/ds/linkedlistds.h>
#include <lib/ds/graphds.h>
#include <lib/ds/mathds.h>
#include <lib/ds/treeds.h>
#include <lib/utils/arrayutil.h>
#include <lib/utils/avltreeutil.h>
#include <lib/utils/bplustreeutil.h>
#include <lib/utils/btreeutil.h>
#include <lib/utils/commonutil.h>
#include <lib/utils/dillutil.h>
#include <lib/utils/graphutil.h>
#include <lib/utils/mathutil.h>
#include <lib/utils/redblacktreeutil.h>
#include <lib/utils/sillutil.h>
#include <lib/utils/treeutil.h>
#include <lib/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef TREEHUFFMANDECODING_H_
#define TREEHUFFMANDECODING_H_

/*struct node{
    int freq;
    char data;
    node * left;
    node * right;
};*/

//Tested
void getCodes(node *ptr,string str,map<string,char> &codes){
	if(ptr == null){
		return;
	}
	if(ptr->left == null && ptr->right == null){
		codes.insert(pair<string,char>(str,ptr->data));
		return;
	}
	unsigned int index = str.size();
	str.insert(index,"0");
	getCodes(ptr->left,str,codes);
    str.erase(index);
	str.insert(index,"1");
	getCodes(ptr->right,str,codes);
}

//Tested
void decode_huff(node * root,string s){
	string str;
	string subString;
	map<string,char> codes;
	map<string,char>::iterator itToCodes;
	getCodes(root,str,codes);
	unsigned int outerCounter = 0,innerCounter;
	while(outerCounter < s.size()){
		innerCounter = outerCounter;
		subString = s.substr(innerCounter,1);
		while((itToCodes = codes.find(subString)) == codes.end()){
			innerCounter++;
			subString = s.substr(outerCounter,innerCounter-outerCounter+1);
		}
		printf("%c",itToCodes->second);
		outerCounter = innerCounter+1;

	}
}

#endif /* TREEHUFFMANDECODING_H_ */

/****************************************************************************************************************************************************/
/*                                                               MAIN CODE END                                                                      */
/****************************************************************************************************************************************************/
