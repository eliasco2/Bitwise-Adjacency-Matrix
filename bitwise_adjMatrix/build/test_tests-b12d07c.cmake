add_test( [==[int test]==] /workspaces/cs225/bitwise_adjMatrix/build/test [==[int test]==]  )
set_tests_properties( [==[int test]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/bitwise_adjMatrix/build)
add_test( [==[str test]==] /workspaces/cs225/bitwise_adjMatrix/build/test [==[str test]==]  )
set_tests_properties( [==[str test]==] PROPERTIES WORKING_DIRECTORY /workspaces/cs225/bitwise_adjMatrix/build)
set( test_TESTS [==[int test]==] [==[str test]==])