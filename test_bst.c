/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for BST
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for binary search tree.
 * ----------------------------------------------------------
 */

#include "test_bst.h"
#include "bst.h"
#include "allocator.h"

#include "general.h"
#include <stdio.h>
#include <string.h>


#define ASSERT_VALID_BST(aggr_fn) _assert_valid_tree(tc, aggr_fn)
static Tree _assert_valid_tree(struct TestCase* tc, aggregator_fn* aggr_fn) {
    Tree tree = tree_acquire(aggr_fn);
    ASSERT_TRUE(tree != 0, MSG("Could not acquire the BST, expected a non-null pointer"));
    ASSERT_TRUE(tree_is_valid(tree), MSG("Expected a valid BST instance"));
    return tree;
}

#define ASSERT_VALID_AWARDED_KICKER(name, club, year, votes) _assert_valid_awarded_kicker(tc, name, club, year, votes)
static AwardedKicker _assert_valid_awarded_kicker(struct TestCase* tc, c_str name, c_str club, int year, int votes) {
    AwardedKicker kicker = kicker_acquire(name, club, year, votes);
    ASSERT_TRUE(kicker != 0, MSG("Could not acquire the kicker records, expected a non-null pointer"));
    ASSERT_TRUE(kicker_is_valid(kicker), MSG("Expected a valid kicker instance"));
    return kicker;
}

static size_t visit_idx = 0;
static c_str labels[] =      { "O", "F", "V", "C", "S", "K", "X", "H", "E", "M", "Q", "U", "A", "L", "G", "R", "J", "Z", "B", "P", "W", "D", "T", "I", "N", "Y" };
static c_str labels_asc[]  = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };
static c_str labels_desc[] = { "Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A" };
static c_str labels_pre[] =  { "O", "F", "C", "A", "B", "E", "D", "K", "H", "G", "J", "I", "M", "L", "N", "V", "S", "Q", "P", "R", "U", "T", "X", "W", "Z", "Y" };
static c_str labels_post[] = { "B", "A", "D", "E", "C", "G", "I", "J", "H", "L", "N", "M", "K", "F", "P", "R", "Q", "T", "U", "S", "W", "Y", "Z", "X", "V", "O" };
static size_t label_cnt = sizeof(labels) / sizeof(labels[0]);
struct TestCase* cur_tc = 0;


int test_aggregation(AwardAggregation aggregation, AwardedKicker kicker) {
    struct TestCase* tc = cur_tc;
    ASSERT_TRUE(aggregation != 0, MSG("AwardAggregation for aggregation was 0"));
    ASSERT_TRUE(kicker != 0, MSG("AwardedKicker for aggregation was 0"));
    if (aggr_get_aspect_text(aggregation) == 0) {
        aggr_set_aspect_text(aggregation, kicker_get_name(kicker));
    }
    return strcmp(kicker_get_name(kicker), aggr_get_aspect_text(aggregation));
}

void test_payload(AwardAggregation a, c_str exp_aspect) {
    struct TestCase* tc = cur_tc;
    ASSERT_TRUE(aggr_is_valid(a), MSG("#%d: Expected valid aggregation record", visit_idx));
    if(a != 0) {
        c_str aspect = aggr_get_aspect_text(a);
        ASSERT_TRUE(strcmp(aspect, exp_aspect) == 0, MSG("#%d: Expected record '%s' but got '%s'", visit_idx, exp_aspect, aspect));
    }
    visit_idx++;
}

void test_ascending(AwardAggregation a) {
    test_payload(a, labels_asc[visit_idx]);
}

void test_descending(AwardAggregation a) {
    test_payload(a, labels_desc[visit_idx]);
}

void test_preorder(AwardAggregation a) {
    test_payload(a, labels_pre[visit_idx]);
}

void test_postorder(AwardAggregation a) {
    test_payload(a, labels_post[visit_idx]);
}

/* ------------------------------------------------------------------- */

TEST(test_tree_acquire__shall_allocate_a_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    tree_release(&t);
}

TEST(test_tree_release__shall_release_an_allocated_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    tree_release(&t);
    ASSERT_TRUE(t == 0, MSG("Expected pointer to tree instance was set to 0 after release"));
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_release__shall_not_release_an_invalid_tree) {
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST(0);
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
    tree_release(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_is_valid__shall_return_true_for_a_valid_tree) {
    Tree t = ASSERT_VALID_BST(0);
    ASSERT_TRUE(tree_is_valid(t), MSG("Expected a valid tree"));
    tree_release(&t);
}

TEST(test_tree_is_valid__shall_return_false_for_an_invalid_tree) {
    Tree t = 0;
    ASSERT_FALSE(tree_is_valid(t), MSG("Expected an invalid tree"));
}

TEST(test_tree_is_empty__shall_return_true_for_empty_and_invalid_trees) {
    Tree t = ASSERT_VALID_BST(0);
    ASSERT_TRUE(tree_is_empty(t), MSG("Expected an empty tree"));
    tree_release(&t);
    ASSERT_TRUE(tree_is_empty(0), MSG("Expected that an invalid tree is empty"));
}

TEST(test_tree_is_empty__shall_return_false_for_non_empty_trees) { 
    mem_reset_stat();
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("NAME", "CLUB", 1976, 1234);
    tree_add(t, k);
    kicker_release(&k);
    ASSERT_FALSE(tree_is_empty(t), MSG("Expected a non-empty tree"));
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_get_size__shall_return_number_of_nodes) {
    mem_reset_stat();
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    size_t exp_val = 0;
    size_t act_val = 0;
    for (size_t idx = 0; idx < label_cnt; idx++) {
        act_val = tree_get_size(t);
        ASSERT_TRUE(act_val == exp_val, MSG("Expected size of %d but got %d", exp_val, act_val));
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        exp_val++;
        kicker_release(&k);
    }
    tree_release(&t);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_tree_get_height__shall_return_height_of_the_tree) {
    mem_reset_stat();
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    int exp_val = -1;
    int act_val = tree_get_height(t);
    ASSERT_TRUE(exp_val == exp_val, MSG("Expected height of %d but got %d", exp_val, act_val));
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        exp_val = (idx == 0 ? 0 : idx < 3 ? 1 : idx < 7 ? 2 : idx < 13 ? 3 : idx < 23 ? 4 : 5);
        act_val = tree_get_height(t);
        ASSERT_TRUE(exp_val == exp_val, MSG("Expected height of %d but got %d", exp_val, act_val));
        kicker_release(&k);
    }
    tree_release(&t);
}

TEST(test_tree_get__shall_provide_added_nodes) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        kicker_release(&k);
    }
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardAggregation a = tree_get(t, labels[idx]);
        ASSERT_TRUE(aggr_is_valid(a), MSG("#%d: Expected valid aggregation record", idx));
        if (a != 0) {
            ASSERT_TRUE(strcmp(aggr_get_aspect_text(a), labels[idx]) == 0, MSG("#%d: Expected aggregation record aspect '%s' but got '%s'", idx, labels[idx], aggr_get_aspect_text(a)));
        }
    }

    tree_release(&t);
}

TEST(test_tree_visit_ascending__shall_visit_all_nodes_in_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        kicker_release(&k);
    }
    visit_idx = 0;
    tree_visit_ascending(t, &test_ascending);
    tree_release(&t);
}

TEST(test_tree_visit_descending__shall_visit_all_nodes_reverse_in_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        kicker_release(&k);
    }
    visit_idx = 0;
    tree_visit_descending(t, &test_descending);
    tree_release(&t);
}

TEST(test_tree_visit_pre_order__shall_visit_all_nodes_pre_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        kicker_release(&k);
    }
    visit_idx = 0;
    tree_visit_pre_order(t, &test_preorder);
    tree_release(&t);

    // printf("\n");
    // for (int i = 0; i < 26; i++) {
    //     printf("\"%s\", ", res[i]);
    // }
}

TEST(test_tree_visit_post_order__shall_visit_all_nodes_post_order) {
    cur_tc = tc;
    Tree t = ASSERT_VALID_BST(&test_aggregation);
    for (size_t idx = 0; idx < label_cnt; idx++) {
        AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(labels[idx], "CLUB", 1976, 1234);
        tree_add(t, k);
        kicker_release(&k);
    }
    visit_idx = 0;
    tree_visit_post_order(t, &test_postorder);
    tree_release(&t);

    // printf("\n");
    // for (int i = 0; i < 26; i++) {
    //     printf("\"%s\", ", res[i]);
    // }
}
