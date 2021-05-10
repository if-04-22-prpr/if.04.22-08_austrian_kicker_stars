/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Binary Search Tree (BST)
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * The declaration of an abstract data type of a binary search tree.
 * ----------------------------------------------------------
 */

#ifndef ___BINARY_SEARCH_TREE__H
#define ___BINARY_SEARCH_TREE__H


/** The type of the binary search tree named Tree. */

/**
 * Acquires ('creates') and provides a 'new' tree instance.
 * Any tree acquired via this function MUST be released using
 * function `tree_release()`.
 * 
 * Note: This function does not make any assumptions 
 * about how tree components, esp. nodes, are allocated.
 * 
 * @param aggregator The aggregator function for aggregating added kickers. 
 * @return The BST instance or 0, if no tree could by instantiated
 * or if the aggregator function is 0.
 */
<type> tree_acquire(aggregator_fn* aggregator);

/**
 * Releases a tree that was obtained earlier via function `tree_obtain`.
 * Released trees MUST NOT be used anymore. Any instances that are
 * associated with the tree are released as well.
 * 
 * Note: The implementation of this function does not make any assumptions
 * about the allocation method of tree elements, but MUST match the implementation
 * of function `tree_acquire` as its inverse function.
 * 
 * @param p_tree The pointer to the tree to release. The value of the pointer
 * is set to 0, if the tree was successfully released, otherwise it is left untouched.
 */
void tree_release(Tree* p_tree);

/**
 * Determines whether or not the given tree is valid.
 * A tree is valid if it is not 0.
 * 
 * @param tree The tree to evaluate.
 * @return `True` if the tree is valid, false otherwise.
 */
<type> tree_is_valid(<params>);

/**
 * Determines whether or not the tree contains at least one node.
 * 
 * @param tree The tree to evaluate.
 * @return `False` if the tree contains one or more nodes, `true` otherwise.
 */
<type> tree_is_empty(<params>);

/**
 * Provides the number of nodes the tree consists of.
 * 
 * @param tree The tree to evaluate.
 * @return The size of the tree.
 */
size_t tree_get_size(<params>);

/**
 * Provides the height of the tree.
 * 
 * @param tree The tree to evaluate.
 * @return The height of the tree. It is 0 if the tree 
 * only consists of a root node and -1, if the tree is empty.
 */
<type> tree_get_height(<params>);

/**
 * Provides the awarded aggregation data stored within the tree for the given aspect text
 * (name or club of the kicker, depending on the associated aggregation function).
 * 
 * @param tree The tree from which the data shall be retrieved.
 * @param text The null-terminated string of the requested aggregation aspect.
 * @return The requested data or 0, if no data for the requested text are available.
 */
<type> tree_get(<params>, c_str text);

/**
 * Aggregates the given kicker to the given tree using the aggregator function
 * associated with the tree.
 * 
 * Important note regarding memory management: 
 * + The `kicker` instance is only referenced during the runtime of the function.
 * The provided kicker instance MAY BE (and possibly MUST BE) released after this call.
 * by the caller. It is NOT released with the tree.
 * 
 * @param tree The tree to which the kicker shall be added.
 * @param kicker The kicker to aggregate.
 */
<type> tree_add(<params>, AwardedKicker kicker);

/**
 * Builds a new tree ordered according to the given indexer function
 * based on the given tree. This allows to order the tree data
 * by different aspects.
 * 
 * Important note regarding memory management: 
 * + The returned `Tree` instance MUST be released by the call of this function.
 * + Aggregation nodes of the new Tree are copies (using aggr_acquire_copy(…)) of 
 * the aggregation nodes of the source tree. Therefore aggregation nodes of both
 * tree can and must be released independently (by releasing the according tree).
 * 
 * @param source The source tree from which a new index tree is created.
 * @param indexer The comparator function for building the index tree.
 * @return The new instance of the index tree. 
 */
Tree tree_build_index_tree(<params>, comparator_fn* indexer);

/**
 * Traverses the binary search tree in a way that visits all nodes
 * in ascending order of their index or aggregation aspect.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type> tree_visit_ascending(<params>, visitor_fn* visitor);

/**
 * Traverses the binary search tree in a way that visits all nodes
 * in descending order of their index or aggregation aspect.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type> tree_visit_descending(<params>);

/**
 * Traverses the binary search tree using pre-order traversal scheme.
 * All nodes are visited by invoking the given `visitor` function.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type> tree_visit_pre_order(<params>) ;

/**
 * Traverses the binary search tree using post-order traversal scheme.
 * All nodes are visited by invoking the given `visitor` function.
 * 
 * @param tree The tree to traverse.
 * @param visitor The function that is invoked for each node.
 */
<type> tree_visit_post_order(<params>);

#endif
