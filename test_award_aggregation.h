/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Unit Tests for Award Aggregation ADT implementation
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions of Award Aggregation ADT.
 * ----------------------------------------------------------
 */
#ifndef ___TEST_AWARD_AGGREGATION_H
#define ___TEST_AWARD_AGGREGATION_H

#include "shortcut.h"

TEST(test_aggr_acquire__shall_allocate_an_aggregation);
TEST(test_aggr_acquire_copy__shall_provide_a_clone_instance);
TEST(test_aggr_release__shall_release_an_allocated_aggregation);
TEST(test_aggr_release__shall_not_release_an_invalid_aggregation);

TEST(test_aggr_is_valid__shall_return_true_for_a_valid_aggregation);
TEST(test_aggr_is_valid__shall_return_false_for_an_invalid_aggregation);

TEST(test_aggr_get_aspect_text__shall_return_the_aspect_text);
TEST(test_aggr_get_assoc_text__shall_provide_associated_texts_and_count_accordingly);
TEST(test_aggr_get_total_votes__shall_return_the_total_votes);
TEST(test_aggr_get_award_count__shall_return_the_according_number_of_awards);

#endif
