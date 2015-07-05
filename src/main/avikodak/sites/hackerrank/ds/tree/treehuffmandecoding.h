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
#include <algorithm/constants/constants.h>
#include <algorithm/ds/commonds.h>
#include <algorithm/ds/linkedlistds.h>
#include <algorithm/ds/graphds.h>
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
#include <algorithm/utils/treeutil.h>
#include <algorithm/utils/twofourtreeutil.h>

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
