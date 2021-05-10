/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: n/a
 * ---------------------------------------------------------
 * Title:			Implementation of UTs for Awarded Kicker ADT
 * Author:			S. Schraml
 * ----------------------------------------------------------
 * Description:
 * Tests functions for Awarded Kicker ADT.
 * ----------------------------------------------------------
 */

#include "test_awarded_kicker.h"
#include "awarded_kicker.h"
#include "allocator.h"

#include "general.h"
#include <stdio.h>
#include <string.h>


#define ASSERT_VALID_AWARDED_KICKER(name, club, year, votes) _assert_valid_awarded_kicker(tc, name, club, year, votes)
static AwardedKicker _assert_valid_awarded_kicker(struct TestCase* tc, c_str name, c_str club, int year, int votes) {
    AwardedKicker kicker = kicker_acquire(name, club, year, votes);
    ASSERT_TRUE(kicker != 0, MSG("Could not acquire the kicker records, expected a non-null pointer"));
    ASSERT_TRUE(kicker_is_valid(kicker), MSG("Expected a valid kicker instance"));
    return kicker;
}

/* ------------------------------------------------------------------- */

TEST(test_kicker_acquire__shall_allocate_a_kicker) {
    mem_reset_stat();
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", "C", 1, 9);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    kicker_release(&k);
}

TEST(test_kicker_release__shall_release_an_allocated_kicker) {
    mem_reset_stat();
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", "C", 1, 9);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 1, MSG("Expected one allocation"));
    kicker_release(&k);
    ASSERT_TRUE(k == 0, MSG("Expected pointer to kicker instance was set to 0 after release"));
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_kicker_release__shall_not_release_an_invalid_kicker) {
    mem_reset_stat();
    AwardedKicker k = 0;
    kicker_release(&k);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
    kicker_release(0);
    ASSERT_TRUE(mem_get_allocated_block_cnt() == 0, MSG("Expected all allocated blocks are freed"));
}

TEST(test_kicker_is_valid__shall_return_true_for_a_valid_kicker) {
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", "C", 1, 9);
    ASSERT_TRUE(kicker_is_valid(k), MSG("Expected a valid kicker"));
    kicker_release(&k);
}

TEST(test_kicker_is_valid__shall_return_false_for_an_invalid_kicker) {
    AwardedKicker k = 0;
    ASSERT_FALSE(kicker_is_valid(k), MSG("Expected an invalid kicker"));
}

TEST(test_kicker_get_name__shall_return_the_name) {
    c_str act_str = kicker_get_name(0);
    ASSERT_TRUE(act_str == 0, MSG("Expected the name provided for an invalid kicker instance is 0 but is '%s'", act_str));

    c_str exp_str = "Famous Name";
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER(exp_str, "C", 1, 9);
    act_str = kicker_get_name(k);
    ASSERT_TRUE(strcmp(exp_str, act_str) == 0, MSG("Expected the name provided by kicker instance is '%s' but is '%s'", exp_str, (act_str != 0 ? act_str : "0")));
    kicker_release(&k);
}

TEST(test_kicker_get_club__shall_return_the_club) {
    c_str act_str = kicker_get_club(0);
    ASSERT_TRUE(act_str == 0, MSG("Expected the club provided for an invalid kicker instance is 0 but is '%s'", act_str));

    c_str exp_str = "Famous Club";
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", exp_str, 1, 9);
    act_str = kicker_get_club(k);
    ASSERT_TRUE(strcmp(exp_str, act_str) == 0, MSG("Expected the club provided by kicker instance is '%s' but is '%s'", exp_str, (act_str != 0 ? act_str : "0")));
    kicker_release(&k);
}

TEST(test_kicker_get_votes__shall_return_the_votes) {
    int act_val = kicker_get_votes(0);
    ASSERT_TRUE(act_val == 0, MSG("Expected the votes provided for an invalid kicker instance are 0 but is '%d'", act_val));
    
    int exp_val = 123456;
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", "C", 9, exp_val);
    act_val = kicker_get_votes(k);
    ASSERT_TRUE(act_val == exp_val, MSG("Expected the votes provided by kicker instance are '%d' but is '%d'", exp_val, act_val));
    kicker_release(&k);
}

TEST(test_kicker_get_award_year__shall_return_the_award_year) {
    int act_val = kicker_get_award_year(0);
    ASSERT_TRUE(act_val == 0, MSG("Expected the year provided for an invalid kicker instance is 0 but is '%d'", act_val));

    int exp_val = 1987;
    AwardedKicker k = ASSERT_VALID_AWARDED_KICKER("N", "C", exp_val, 1);
    act_val = kicker_get_award_year(k);
    ASSERT_TRUE(act_val == exp_val, MSG("Expected the year provided by kicker instance is '%d' but is '%d'", exp_val, act_val));
    kicker_release(&k);
}