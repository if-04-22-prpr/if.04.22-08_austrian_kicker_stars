/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: S08
 * Title:			Binary Search Tree implementation
 * Author:			*/<your name>;/*
 * ----------------------------------------------------------
 * Description:
 * Implementation of a binary search tree.
 * ----------------------------------------------------------
 */

#include "bst.h"
#include "allocator.h"

/** The type of the binary search tree node named TreeNode. */

/** The implementation of tree node data */

/** The implementation of tree data */

/* ===================================================================== */
/* private function declarations */

/** 
 * The data struct providing arguments for visiting tree nodes. 
 * This struct covers data of all required use case. Depending
 * on the concrete use case, some attributes may be 0.
 */
typedef struct {
    visitor_fn* payload_visitor;
    comparator_fn* payload_comparator;
    Tree target_tree;
} TreeNodeVisitorData;

/** The function pointer type for visiting tree nodes. */
typedef void node_visitor_fn(TreeNode node, TreeNodeVisitorData* visitor_data);

/** 
 * Acquires a single tree node and initializes its members, including the given payload. 
 */
static TreeNode tree_node_acquire(AwardAggregation payload);

/** 
 * Release a single tree node and its payload. 
 * Matches 'node_visitor_fn' signature, no attribute of 'visitor_data' is required.
 */
static void tree_node_release(TreeNode node, TreeNodeVisitorData* visitor_data);

/**
 * Calculates the height of the given node.
 * 
 * @param node The node from which the height is calculated.
 * @return The height of the tree from the given node or 0, if the node is 0.
 */
static int tree_node_get_height(TreeNode node);

/**
 * The adapter function for visiting the payload of a visited node.
 * Matches 'node_visitor_fn' signature, requires attribute 'visitor_fn' of 
 * provided `visitor_data`.
 * 
 * @param node The visited node.
 * @param visitor The function to be invoked for the node's payload.
 */
static void tree_node_visit_payload(TreeNode node, TreeNodeVisitorData* visitor_data);

/**
 * Traverses the tree according to 'Pre-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param payload_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_pre_order(TreeNode root, node_visitor_fn* node_visitor, TreeNodeVisitorData* visitor_data);

/**
 * Traverses the tree according to 'In-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param payload_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_in_order(TreeNode root, node_visitor_fn* node_visitor, TreeNodeVisitorData* visitor_data);

/**
 * Traverses the tree according to 'Reverse-In-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param payload_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_reverse_in_order(TreeNode root, node_visitor_fn* node_visitor, TreeNodeVisitorData* visitor_data);

/**
 * Traverses the tree according to 'Post-Order' scheme and visits
 * each node using the 'node_visitor' function.
 * 
 * @param root The root of the tree to traverse
 * @param node_visitor The function that is invoked for each visited node.
 * @param payload_visitor The function that is invoked for the payload of each visited node, may be 0.
 */
static void tree_traverse_post_order(TreeNode root, node_visitor_fn* node_visitor, TreeNodeVisitorData* visitor_data);

/* ===================================================================== */

static void tree_node_build_index(TreeNode src_node, TreeNode target_node, TreeNode target_parent, TreeNodeVisitorData* data);

static void tree_node_build_index_adapter(TreeNode node, TreeNodeVisitorData* data);


