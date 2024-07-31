# Standard library, lambdas and templates

In this task, you will write 3 functions, that will use: std::accumulate, std::reduce std::transform and std::minmax_element. Each function uses only one of the std::* and each std::* is used by only one function.

To make thinks even simpler, the input will always be a std::vector of some type T (use templates). For each function, you will also get additional information of what you can expect of this T type.

Functions:
- count_trues(...)
    - type T can be (explicitally) converted to bool
    - returns std::size_t - the number of true's in the given vector

- sum_it_up(...)
    - type T has + operator and the operation is commutative
    - returns T - the sum of elements in the vector

- increment(...)
    - type T has preincrement (++T{}) operator
    - modifies the input vector by incrementing each element
    - does not return any value

- find_bounds(...)
    - type T has < operator
    - returns std::pair<T, T>, i. e. {min, max} of the given vector.



Note: There are no tests, but I wrote some helper functions, so you can easily test it yourself. Do not write templates as I did for the helpers, it is not pretty, find out how to write templates yourself. You also do not need to create any new file or midify cmake. As an input, use for example std::vector<int>. 