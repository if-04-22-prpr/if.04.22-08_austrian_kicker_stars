/*----------------------------------------------------------
 *				HTBLA-Leonding
 * ---------------------------------------------------------
 * Title:			Tests implementation of a Liked List.
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Unit tests for a linked list implemenation.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#include "shortcut.h"
#include "test_awarded_kicker.h"
#include "test_award_aggregation.h"
#include "test_functions.h"
#include "test_bst.h"

int main(int argc, char *argv[])
{
	/* AWARDED KICKER */
	ADD_TEST(test_kicker_acquire__shall_allocate_a_kicker);
	ADD_TEST(test_kicker_release__shall_release_an_allocated_kicker);
	ADD_TEST(test_kicker_release__shall_not_release_an_invalid_kicker);
	ADD_TEST(test_kicker_is_valid__shall_return_true_for_a_valid_kicker);
	ADD_TEST(test_kicker_is_valid__shall_return_false_for_an_invalid_kicker);
	ADD_TEST(test_kicker_get_name__shall_return_the_name);
	ADD_TEST(test_kicker_get_club__shall_return_the_club);
	ADD_TEST(test_kicker_get_votes__shall_return_the_votes);
	ADD_TEST(test_kicker_get_award_year__shall_return_the_award_year);

	/* AWARD AGGREGATION */
	ADD_TEST(test_aggr_acquire__shall_allocate_an_aggregation);
	ADD_TEST(test_aggr_acquire_copy__shall_provide_a_clone_instance);
	ADD_TEST(test_aggr_release__shall_release_an_allocated_aggregation);
	ADD_TEST(test_aggr_release__shall_not_release_an_invalid_aggregation);

	ADD_TEST(test_aggr_is_valid__shall_return_true_for_a_valid_aggregation);
	ADD_TEST(test_aggr_is_valid__shall_return_false_for_an_invalid_aggregation);

	ADD_TEST(test_aggr_get_aspect_text__shall_return_the_aspect_text);
	ADD_TEST(test_aggr_get_assoc_text__shall_provide_associated_texts_and_count_accordingly);
	ADD_TEST(test_aggr_get_total_votes__shall_return_the_total_votes);
	ADD_TEST(test_aggr_get_award_count__shall_return_the_according_number_of_awards);

	/* FUNCTIONS */
	ADD_TEST(test_aggregate_by_name);
	ADD_TEST(test_aggregate_by_club);
	ADD_TEST(test_compare_by_votes);
	ADD_TEST(test_compare_by_awards);
	ADD_TEST(test_compare_by_assoc_text_count);

	/* BST */
	ADD_TEST(test_tree_acquire__shall_allocate_a_tree);
	ADD_TEST(test_tree_release__shall_release_an_allocated_tree);
	ADD_TEST(test_tree_release__shall_not_release_an_invalid_tree);

	ADD_TEST(test_tree_is_valid__shall_return_true_for_a_valid_tree);
	ADD_TEST(test_tree_is_valid__shall_return_false_for_an_invalid_tree);

	ADD_TEST(test_tree_is_empty__shall_return_true_for_empty_and_invalid_trees);
	ADD_TEST(test_tree_is_empty__shall_return_false_for_non_empty_trees);

	ADD_TEST(test_tree_get_size__shall_return_number_of_nodes);
	ADD_TEST(test_tree_get_height__shall_return_height_of_the_tree);

	ADD_TEST(test_tree_get__shall_provide_added_nodes);
	ADD_TEST(test_tree_visit_ascending__shall_visit_all_nodes_in_order);
	ADD_TEST(test_tree_visit_descending__shall_visit_all_nodes_reverse_in_order);
	ADD_TEST(test_tree_visit_pre_order__shall_visit_all_nodes_pre_order);
	ADD_TEST(test_tree_visit_post_order__shall_visit_all_nodes_post_order);

	run_tests();
	return 0;
}
