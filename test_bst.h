/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for BST implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of binary search tree.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_BST_H
#define ___TEST_BST_H

#include "shortcut.h"

TEST(test_tree_acquire__shall_allocate_a_tree);
TEST(test_tree_release__shall_release_an_allocated_tree);
TEST(test_tree_release__shall_not_release_an_invalid_tree);

TEST(test_tree_is_valid__shall_return_true_for_a_valid_tree);
TEST(test_tree_is_valid__shall_return_false_for_an_invalid_tree);

TEST(test_tree_is_empty__shall_return_true_for_empty_and_invalid_trees);
TEST(test_tree_is_empty__shall_return_false_for_non_empty_trees);

TEST(test_tree_get_size__shall_return_number_of_nodes);
TEST(test_tree_get_height__shall_return_height_of_the_tree);

TEST(test_tree_get__shall_provide_added_nodes);
TEST(test_tree_visit_ascending__shall_visit_all_nodes_in_order);
TEST(test_tree_visit_descending__shall_visit_all_nodes_reverse_in_order);
TEST(test_tree_visit_pre_order__shall_visit_all_nodes_pre_order);
TEST(test_tree_visit_post_order__shall_visit_all_nodes_post_order);

#endif
