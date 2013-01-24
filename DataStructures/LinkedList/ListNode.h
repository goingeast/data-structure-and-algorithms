//
//  listNode.h
//  LInkedList
//
//  Created by Haoru Zhao on 2/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef LinkedList_listNode_h
#define LinkedList_listNode_h
template<class value_type>
class listNode 
{
    //friend class linkedList;
public:

    listNode(const value_type& initData = value_type(), listNode* initLink = NULL)
		:dataField(initData),linkField(initLink){
    };
//----------------------------<>-----------------------------------
    void setData(const value_type& newData){
		dataField = newData;
	};
    void setLink(listNode* newNode){
		linkField = newNode; 
	};
//-----------------------------<>----------------------------------
    value_type getDate(){
		return dataField;
	};
//------------------------------<>---------------------------------
	const listNode* getLink() const {
		return linkField;
	};
    listNode* getLink(){
		return linkField;
	};
private:
    value_type dataField;
    listNode* linkField;
}; 


#endif
