#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
#include <numeric>

namespace ranges = std::ranges;
using V = std::vector<std::vector<int>>;

template <typename T>
auto three_sum (T& nums ) ->V
{
    V result{};
    if ( nums.size() < 3) { return result; }
    else if ( nums.size() == 3 || nums.size() == 4 ) {
        if ( ranges::all_of(nums, [](int i) { return i == 0; }) ) {
            result.push_back( {nums[0],nums[1],nums[2]} );
            return result;
        }
    }
    //
    ranges::sort( nums );
    //
    std::size_t size = nums.size();
    for ( std::size_t i=0, first{}, last{}; i < size-2 ; ++i ) {
        if (i>0 && nums.at(i) == nums.at(i-1) ) { continue; }
        first = i+1;
        last = nums.size()-1;
        //
        while ( first < last ) {
            int sum =  nums.at(first) + nums.at(last);
            if ( sum > -nums.at(i) ) { --last; }
            else if ( sum < -nums.at(i) ) { ++first; }
            else {
                result.push_back( {nums.at(i),nums.at(first), nums.at(last)} );
                while (first<last && nums.at(first) == nums.at(first+1) ) ++first;
                while (first<last && nums.at(last) == nums.at(last-1) ) --last;
                ++first;
                --last;
            }
        }
    }
  return result;
}

auto main() ->int
{
    std::vector<int> nums =/* {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0}; */ { 0,0,0,0};
    auto result = three_sum( nums );
    for ( std::size_t i = 0; i < result.size(); ++i ) {
        for ( std::size_t j = 0; j < result.at(0).size(); ++j ) {
            std::cout << result.at(i).at(j);
        }
        std::cout << ',';
    }
 }
