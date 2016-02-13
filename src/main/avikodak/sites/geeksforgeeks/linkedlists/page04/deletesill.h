/****************************************************************************************************************************************************
 *  File Name                   : deletesill.h
 *  File Location               : /algos_v2/src/main/avikodak/sites/geeksforgeeks/linkedlists/page04/deletesill.h
 *  Created on                  : Feb 7, 2016 :: 12:31:14 PM
 *  Author                      : avikodak
 *  Testing Status              : TODO
 *  URL                         : http://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
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
#include <stdexcept>
#include <limits.h>
#include <stdint.h>
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

#ifndef MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_DELETESILL_H_
#define MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_DELETESILL_H_

/****************************************************************************************************************************************************/
/*                                                            O(N) Algorithm                                                                        */
/****************************************************************************************************************************************************/
void itDeleteSill(sillNode **head){
	if(*head == null){
		return;
	}
	sillNode *crawler = *head,*temp;
	while(crawler != null){
		temp = crawler;
		crawler = crawler->next;
		free(temp);
	}
	(*head) = null;
}

void deleteSill(sillNode **head){
	if(*head == null){
		return;
	}
	deleteSill(&((*head)->next));
	free(*head);
	(*head) = null;
}

void deleteSillAuxSpace(sillNode **head){
	if(*head == null){
		return;
	}
	stack<sillNode *> auxSpace;
	sillNode *crawler = *head;
	while(crawler != null){
		auxSpace.push(crawler);
		crawler = crawler->next;
	}
	while(!auxSpace.empty()){
		crawler = auxSpace.top();
		auxSpace.pop();
		free(crawler);
	}
	(*head) = null;
}

#endif /* MAIN_AVIKODAK_SITES_GEEKSFORGEEKS_LINKEDLISTS_PAGE04_DELETESILL_H_ */
