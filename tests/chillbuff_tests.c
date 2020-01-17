/*
   Copyright 2020 Raphael Beck

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "../include/chillbuff.h"

/* A test case that does nothing and succeeds. */
static void null_test_success(void** state)
{
    (void)state;
}

static void chillbuff_init_buff_arg_null_returns_CHILLBUFF_NULL_ARG(void** state)
{
    assert_int_equal(CHILLBUFF_NULL_ARG, chillbuff_init(NULL, 8, 1, CHILLBUFF_GROW_DUPLICATIVE));
}

static void chillbuff_element_size_0_returns_CHILLBUFF_INVALID_ARG(void** state)
{
    chillbuff b;
    assert_int_equal(CHILLBUFF_INVALID_ARG, chillbuff_init(&b, 16, 0, CHILLBUFF_GROW_DUPLICATIVE));
}

static void chillbuff_element_invalid_grow_method_returns_CHILLBUFF_INVALID_ARG(void** state)
{
    chillbuff b;
    assert_int_equal(CHILLBUFF_INVALID_ARG, chillbuff_init(&b, 16, 1, -1));
    assert_int_equal(CHILLBUFF_INVALID_ARG, chillbuff_init(&b, 16, 1, 200));
}

static void chillbuff_init_returns_CHILLBUFF_SUCCESS(void** state)
{
    chillbuff b;
    assert_int_equal(CHILLBUFF_SUCCESS, chillbuff_init(&b, 16, 1, CHILLBUFF_GROW_DUPLICATIVE));
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(null_test_success),
        cmocka_unit_test(chillbuff_init_buff_arg_null_returns_CHILLBUFF_NULL_ARG),
        cmocka_unit_test(chillbuff_element_size_0_returns_CHILLBUFF_INVALID_ARG),
        cmocka_unit_test(chillbuff_element_invalid_grow_method_returns_CHILLBUFF_INVALID_ARG),
        cmocka_unit_test(chillbuff_init_returns_CHILLBUFF_SUCCESS),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
