/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for Award Aggregation ADT
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for Award Aggregation ADT.
 * ----------------------------------------------------------
 */

#include "test_award_aggregation.h"
#include "award_aggregation.h"
#include "allocator.h"

#include <stdio.h>
#include <string.h>

#define ASSERT_VALID_AWARD_AGGR(text) _assert_valid_award_aggr(tc, text)
static AwardAggregation _assert_valid_award_aggr(struct TestCase* tc, c_str text) {
    AwardAggregation aggr = aggr_acquire(text);
    ASSERT_TRUE(aggr != 0, MSG("Could not acquire the award aggregation record, expected a non-null pointer"));
    ASSERT_TRUE(aggr_is_valid(aggr), MSG("Expected a valid award aggregation instance"));
    return aggr;
}

/* ------------------------------------------------------------------- */

TEST(test_aggr_acquire__shall_allocate_an_aggregation) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    aggr_release(&a);
}

TEST(test_aggr_acquire_copy__shall_provide_a_clone_instance) {
    mem_reset_stat();
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    c_str str = "aspect";
    c_str str_1 = "t1";
    c_str str_2 = "t2";
    aggr_set_aspect_text(a, str);
    aggr_add_associated_text(a, str_1);
    aggr_add_associated_text(a, str_2);
    aggr_increment_award_count(a);
    aggr_add_votes(a, 6);
    AwardAggregation b = aggr_acquire_copy(a);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 2, MSG("Expected another allocation"));
    ASSERT_FALSE(a == b, MSG("Expected the copy as a separate instance"));
    ASSERT_TRUE(aggr_get_aspect_text(a) == aggr_get_aspect_text(b), MSG("Expected identical aspects texts"));
    ASSERT_TRUE(aggr_get_associated_text_count(a) == aggr_get_associated_text_count(b), MSG("Expected the equal number of associated texts"));
    for (int i = 0; i < aggr_get_associated_text_count(a); i++) {
        ASSERT_TRUE(aggr_get_associated_text(a, i) == aggr_get_associated_text(b, i), MSG("Expected an equal associated text #%d", i));
    }
    ASSERT_TRUE(aggr_get_total_votes(a) == aggr_get_total_votes(b), MSG("Expected the same number of total votes"));
    ASSERT_TRUE(aggr_get_award_count(a) == aggr_get_award_count(b), MSG("Expected the same number of awards"));
    aggr_release(&a);
    aggr_release(&b);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_aggr_release__shall_release_an_allocated_aggregation) {
    mem_reset_stat();
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    aggr_release(&a);
    ASSERT_TRUE(a == 0, MSG("Expected pointer to award aggregation instance was set to 0 after release"));
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_aggr_release__shall_not_release_an_invalid_aggregation) {
    mem_reset_stat();
    AwardAggregation a = 0;
    aggr_release(&a);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
    aggr_release(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_aggr_is_valid__shall_return_true_for_a_valid_aggregation) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("A");
    ASSERT_TRUE(aggr_is_valid(a), MSG("Expected a valid aggregation"));
    aggr_release(&a);
    a = ASSERT_VALID_AWARD_AGGR(0);
    ASSERT_TRUE(aggr_is_valid(a), MSG("Expected a valid aggregation (without aspect text)"));
    aggr_release(&a);
}

TEST(test_aggr_is_valid__shall_return_false_for_an_invalid_aggregation) {
    AwardAggregation a = 0;
    ASSERT_FALSE(aggr_is_valid(a), MSG("Expected an invalid aggregation"));
}

TEST(test_aggr_get_aspect_text__shall_return_the_aspect_text) {
    c_str exp_asp = "aspect";
    c_str false_asp = "no-aspect";
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR(exp_asp);
    c_str act_asp = aggr_get_aspect_text(a);
    ASSERT_TRUE(act_asp == exp_asp, MSG("Expected aspect text '%s' but got '%s'", exp_asp, (act_asp != 0 ? act_asp : "0")));
    aggr_set_aspect_text(a, false_asp);
    act_asp = aggr_get_aspect_text(a);
    ASSERT_TRUE(act_asp == exp_asp, MSG("Expected unchanged aspect text '%s' but got '%s'", exp_asp, (act_asp != 0 ? act_asp : "0")));
    aggr_release(&a);

    a = ASSERT_VALID_AWARD_AGGR(0);
    act_asp = aggr_get_aspect_text(a);
    ASSERT_TRUE(act_asp == 0, MSG("Expected aspect text '0' but got '%s'", (act_asp != 0 ? act_asp : "0")));
    aggr_set_aspect_text(a, exp_asp);
    act_asp = aggr_get_aspect_text(a);
    ASSERT_TRUE(act_asp == exp_asp, MSG("Expected aspect text '%s' but got '%s'", exp_asp, (act_asp != 0 ? act_asp : "0")));
    aggr_release(&a);

}

TEST(test_aggr_get_assoc_text__shall_provide_associated_texts_and_count_accordingly) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("aspect");
    c_str str_1 = "t1";
    c_str str_2 = "t2";
    size_t exp_cnt = 0;
    size_t act_cnt = aggr_get_associated_text_count(a);
    ASSERT_TRUE(exp_cnt == act_cnt, MSG("Expected '%d' associated texts but got '%d'", exp_cnt, act_cnt));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == 0, MSG("Expected '0' if no associated text was applied"));

    aggr_add_associated_text(a, str_1);
    exp_cnt = 1;
    act_cnt = aggr_get_associated_text_count(a);
    ASSERT_TRUE(exp_cnt == act_cnt, MSG("Expected '%d' associated texts but got '%d'", exp_cnt, act_cnt));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == str_1, MSG("Expected the applied associated text @ idx 0"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == 0, MSG("Expected '0' the applied associated text @ idx 1"));

    aggr_add_associated_text(a, str_2);
    exp_cnt = 2;
    act_cnt = aggr_get_associated_text_count(a);
    ASSERT_TRUE(exp_cnt == act_cnt, MSG("Expected '%d' associated texts but got '%d'", exp_cnt, act_cnt));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == str_1, MSG("Expected the applied associated text @ idx 0"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == str_2, MSG("Expected the applied associated text @ idx 1"));
    ASSERT_TRUE(aggr_get_associated_text(a, 2) == 0, MSG("Expected '0' the applied associated text @ idx 2"));

    aggr_add_associated_text(a, "t1");
    act_cnt = aggr_get_associated_text_count(a);
    ASSERT_TRUE(exp_cnt == act_cnt, MSG("Expected '%d' associated texts but got '%d'", exp_cnt, act_cnt));
    ASSERT_TRUE(aggr_get_associated_text(a, 0) == str_1, MSG("Expected the applied associated text @ idx 0 is unchanged"));
    ASSERT_TRUE(aggr_get_associated_text(a, 1) == str_2, MSG("Expected the applied associated text @ idx 1"));
    ASSERT_TRUE(aggr_get_associated_text(a, 2) == 0, MSG("Expected '0' the applied associated text @ idx 2"));

    aggr_release(&a);
}

TEST(test_aggr_get_total_votes__shall_return_the_total_votes) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("aspect");
    int exp_val = 0;
    int act_val = aggr_get_total_votes(a);
    ASSERT_TRUE(exp_val == act_val, MSG("Expected '%d' total votes but got '%d'", exp_val, act_val));

    exp_val = 6;
    aggr_add_votes(a, exp_val);
    act_val = aggr_get_total_votes(a);
    ASSERT_TRUE(exp_val == act_val, MSG("Expected '%d' total votes but got '%d'", exp_val, act_val));

    aggr_release(&a);
}

TEST(test_aggr_get_award_count__shall_return_the_according_number_of_awards) {
    AwardAggregation a = ASSERT_VALID_AWARD_AGGR("aspect");
    int exp_val = 0;
    int act_val = aggr_get_award_count(a);
    ASSERT_TRUE(exp_val == act_val, MSG("Expected '%d' number of awards but got '%d'", exp_val, act_val));

    exp_val += 1;
    aggr_increment_award_count(a);
    act_val = aggr_get_award_count(a);
    ASSERT_TRUE(exp_val == act_val, MSG("Expected '%d' number of awards but got '%d'", exp_val, act_val));

    aggr_release(&a);
}
