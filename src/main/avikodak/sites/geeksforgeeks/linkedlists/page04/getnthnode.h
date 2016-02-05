/****************************************************************************************************************************************************
 *  File Name                   : getnthnode.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/linkedlists/page04/getnthnode.h
 *  Created on                  : Feb 4, 2016 :: 11:48:14 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.practice.geeksforgeeks.org/problem-page.php?pid=240
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
#include <libv2/common/commonincludes.h>
#include <libv2/constants/constants.h>
#include <libv2/ds/commonds.h>
#include <libv2/ds/graphds.h>
#include <libv2/ds/linkedlistds.h>
#include <libv2/ds/mathds.h>
#include <libv2/ds/treeds.h>
#include <libv2/utils/abtreeutil.h>
#include <libv2/utils/arrayutil.h>
#include <libv2/utils/avltreeutil.h>
#include <libv2/utils/bplustreeutil.h>
#include <libv2/utils/bstutil.h>
#include <libv2/utils/btreeutil.h>
#include <libv2/utils/commonutil.h>
#include <libv2/utils/dillutil.h>
#include <libv2/utils/graphutil.h>
#include <libv2/utils/ioutil.h>
#include <libv2/utils/mathutil.h>
#include <libv2/utils/redblacktreeutil.h>
#include <libv2/utils/sillutil.h>
#include <libv2/utils/treeutil.h>
#include <libv2/utils/trieutil.h>
#include <libv2/utils/twofourtreeutil.h>

/****************************************************************************************************************************************************/
/*                                                            USER DEFINED CONSTANTS                                                                */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/*                                                             MAIN CODE START                                                                      */
/****************************************************************************************************************************************************/

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_GETNTHNODE_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_GETNTHNODE_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
sillNode *itGetNthNode(sillNode *ptr,unsigned int nValue){
	for(unsigned int counter = 0;counter < nValue;counter++){
		ptr = ptr->next;
	}
	return ptr;
}

sillNode *getNthNode(sillNode *ptr,unsigned int nValue){
	if(nValue == 0){
		return ptr;
	}
	return getNthNode(ptr,nValue-1);
}

sillNode *getNthNodeCaching(sillNode *ptr,unsigned int nValue){
	map<unsigned int,sillNode *> indexNodeMap;
	map<unsigned int,sillNode *>::iterator itToIndexNodeMap;
	unsigned int indexCounter = 0;
	while(ptr != null){
		indexNodeMap.insert(pair<unsigned int,sillNode *>(indexCounter++,ptr));
		ptr = ptr->next;
	}
	return (itToIndexNodeMap = indexNodeMap.find(nValue)) == indexNodeMap.end()?null:itToIndexNodeMap->second;
}

/****************************************************************************************************************************************************/
/*                                                           O(N^2) Algorithm                                                                       */
/****************************************************************************************************************************************************/
sillNode *getNthNodeON2(sillNode *ptr,unsigned int nValue){
	sillNode *outerCrawler = ptr,*innerCrawler;
	while(outerCrawler != null){
		innerCrawler = ptr;
		unsigned int index = 0;
		while(innerCrawler != outerCrawler){
			index++;
			innerCrawler = innerCrawler->next;
		}
		if(index == nValue){
			return outerCrawler;
		}
		outerCrawler = outerCrawler->next;
	}
	return null;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_GETNTHNODE_H_ */
