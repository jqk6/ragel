/*
 *  Copyright 2002 Adrian Thurston <thurston@complang.org>
 */

#ifndef _AAPL_AVLIMELKEY_H
#define _AAPL_AVLIMELKEY_H

#include "compare.h"
#include "dlistmel.h"

/**
 * \addtogroup avlitree 
 * @{
 */

/**
 * \class AvliMelKey
 * \brief Linked AVL tree for element appearing in multiple trees with different keys.
 *
 * AvliMelKey is similar to AvliMel, except that an additional template
 * parameter, BaseKey, is provided for resolving ambiguous references to
 * getKey(). This means that if an element is stored in multiple trees, each
 * tree can use a different key for ordering the elements in it. Using
 * AvliMelKey an array of data structures can be indexed with an O(log(n))
 * search on two or more of the values contained within it and without
 * allocating any additional data.
 *
 * AvliMelKey does not assume ownership of elements in the tree. The destructor
 * will not delete the elements. If the user wishes to explicitly deallocate
 * all the items in the tree the empty() routine is available. 
 *
 * \include ex_avlimelkey.cpp
 */

/*@}*/

#define BASE_EL(name) BaseEl::name
#define BASEKEY(name) BaseKey::name
#define BASELIST DListMel< Element, BaseEl >
#define AVLMEL_CLASSDEF class Element, class Key, class BaseEl, \
		class BaseKey, class Compare = CmpOrd<Key>
#define AVLMEL_TEMPDEF class Element, class Key, class BaseEl, \
		class BaseKey, class Compare
#define AVLMEL_TEMPUSE Element, Key, BaseEl, BaseKey, Compare
#define AvlTree AvliMelKey
#define WALKABLE

#include "avlcommon.h"

#undef BASE_EL
#undef BASEKEY
#undef BASELIST
#undef AVLMEL_CLASSDEF
#undef AVLMEL_TEMPDEF
#undef AVLMEL_TEMPUSE
#undef AvlTree
#undef WALKABLE

#endif /* _AAPL_AVLIMELKEY_H */
