#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>

#include <gtest/gtest.h>
#include "../lib/stl-algorithms/algorithms.h"

using namespace algo;

TEST(Lab11TestSuite, XrangeTest) {

  {
    auto a = xrange(10.5, 15.5);
    std::vector<double> vector{a.begin(), a.end()};
    ASSERT_EQ(vector[0], 10.5);
    ASSERT_EQ(vector[1], 11.5);
    ASSERT_EQ(vector[2], 12.5);
    ASSERT_EQ(vector[3], 13.5);
    ASSERT_EQ(vector[4], 14.5);

    auto b = xrange(5326.5, 5331.5);
    std::deque<double> deque{b.begin(), b.end()};
    ASSERT_EQ(deque[0], 5326.5);
    ASSERT_EQ(deque[1], 5327.5);
    ASSERT_EQ(deque[2], 5328.5);
    ASSERT_EQ(deque[3], 5329.5);
    ASSERT_EQ(deque[4], 5330.5);

    auto c = xrange(5326.5, 5331.5);
    double counter = 5326.5;
    std::list<double> list{c.begin(), c.end()};
    for (auto k : list) {
      ASSERT_EQ(k, counter);
      ++counter;
    }
  }


  {
    auto a = xrange(5);
    std::vector<int> vector{a.begin(), a.end()};
    ASSERT_EQ(vector[0], 0);
    ASSERT_EQ(vector[1], 1);
    ASSERT_EQ(vector[2], 2);
    ASSERT_EQ(vector[3], 3);
    ASSERT_EQ(vector[4], 4);

    auto b = xrange(5);
    std::deque<int> deque{b.begin(), b.end()};
    ASSERT_EQ(deque[0], 0);
    ASSERT_EQ(deque[1], 1);
    ASSERT_EQ(deque[2], 2);
    ASSERT_EQ(deque[3], 3);
    ASSERT_EQ(deque[4], 4);

    auto c = xrange(5);
    int counter = 0;
    std::list<int> list{c.begin(), c.end()};
    for (auto k : list) {
      ASSERT_EQ(k, counter);
      ++counter;
    }
  }

  {
    std::vector vector = {1, 3, 5};
    int counter1 = 0;
    for (auto i : xrange(1, 6, 2)) {
      ASSERT_EQ(i, vector[counter1]);
      ++counter1;
    }

    std::array array = {1, 3, 5};
    int counter2 = 0;
    for (auto i : xrange(1, 6, 2)) {
      ASSERT_EQ(i, array[counter2]);
      ++counter2;
    }

    std::deque deque = {1, 3, 5};
    int counter3 = 0;
    for (auto i : xrange(1, 6, 2)) {
      ASSERT_EQ(i, deque[counter3]);
      ++counter3;
    }
  }

}

TEST(Lab11TestSuite, ZipTest) {

  {
    std::list l = {1, 2, 3, 4, 5};
    std::vector v = {'a', 'b', 'c', 'd'};
    /*
    1 a
    2 b
    3 c
    4 d
    */
    int counter = 0;
    std::vector a = {1, 2, 3, 4, 5};
    std::vector b = {'a', 'b', 'c', 'd'};
    
    for(auto value : zip(l, v)) {
      ASSERT_EQ(value.first, a[counter]);
      ASSERT_EQ(value.second, b[counter]);
      ++counter;
    }
  }

  {
    std::deque l = {50.5, 523.5, 634.6, -625.5, 634.5, 643.62, 63.5};
    std::vector v = {"test", "ok", "testing", "numbers", "one", "more", "another", "one"};
    int counter = 0;
    std::deque a = {50.5, 523.5, 634.6, -625.5, 634.5, 643.62, 63.5};
    std::vector b = {"test", "ok", "testing", "numbers", "one", "more", "another", "one"};
    
    for(auto value : zip(l, v)) {
      ASSERT_EQ(value.first, a[counter]);
      ASSERT_EQ(value.second, b[counter]);
      ++counter;
    }
  }

  {
    std::deque l = {std::make_pair("word", 42), std::make_pair("testing", 643), std::make_pair("ok", 5235), std::make_pair("another", 643)};
    std::list v = {std::make_pair("another", 523), std::make_pair("testings", 652), std::make_pair("four", 2345), std::make_pair("fifth", 36234), std::make_pair("third", 23452)};
    int counter = 0;
    std::deque a = {std::make_pair("word", 42), std::make_pair("testing", 643), std::make_pair("ok", 5235), std::make_pair("another", 643)};
    std::vector b = {std::make_pair("another", 523), std::make_pair("testings", 652), std::make_pair("four", 2345), std::make_pair("fifth", 36234), std::make_pair("third", 23452)};
    
    for(auto value : zip(l, v)) {
      ASSERT_EQ(value.first, a[counter]);
      ASSERT_EQ(value.second, b[counter]);
      ++counter;
    }
  }

}

TEST(AlgorithmsTestSuite, all_of) {

  std::vector vector = {236, 463, 634, 62, 764, 754, 26, 1362};
  ASSERT_TRUE(algo::all_of(vector.begin(), vector.end(), [](int value){return value > 1;}));
  ASSERT_TRUE(algo::all_of(vector.begin(), vector.end(), [](int value){return value < 1363;}));
  ASSERT_FALSE(algo::all_of(vector.begin(), vector.end(), [](int value){return value > 63;}));
  ASSERT_FALSE(algo::all_of(vector.begin(), vector.end(), [](int value){return value < 1361;}));

  std::array array = {236, 463, 634, 62, 764, 754, 26, 1362};
  ASSERT_TRUE(algo::all_of(array.begin(), array.end(), [](int value){return value > 1;}));
  ASSERT_TRUE(algo::all_of(array.begin(), array.end(), [](int value){return value < 1363;}));
  ASSERT_FALSE(algo::all_of(array.begin(), array.end(), [](int value){return value > 63;}));
  ASSERT_FALSE(algo::all_of(array.begin(), array.end(), [](int value){return value < 1361;}));
  
  std::deque deque = {236, 463, 634, 62, 764, 754, 26, 1362};
  ASSERT_TRUE(algo::all_of(deque.begin(), deque.end(), [](int value){return value > 1;}));
  ASSERT_TRUE(algo::all_of(deque.begin(), deque.end(), [](int value){return value < 1363;}));
  ASSERT_FALSE(algo::all_of(deque.begin(), deque.end(), [](int value){return value > 63;}));
  ASSERT_FALSE(algo::all_of(deque.begin(), deque.end(), [](int value){return value < 1361;}));

  std::list list = {236, 463, 634, 62, 764, 754, 26, 1362};
  ASSERT_TRUE(algo::all_of(list.begin(), list.end(), [](int value){return value > 1;}));
  ASSERT_TRUE(algo::all_of(list.begin(), list.end(), [](int value){return value < 1363;}));
  ASSERT_FALSE(algo::all_of(list.begin(), list.end(), [](int value){return value > 63;}));
  ASSERT_FALSE(algo::all_of(list.begin(), list.end(), [](int value){return value < 1361;}));
}

TEST(AlgorithmsTestSuite, any_of) {

  std::vector vector = {6346, 3574, 737, 865, 28, 58, 2, 8658, 2, 8653735, 357848, 336};
  ASSERT_TRUE(algo::any_of(vector.begin(), vector.end(), [](int value){return value == 865;}));
  ASSERT_TRUE(algo::any_of(vector.begin(), vector.end(), [](int value){return value == 8653735;}));
  ASSERT_FALSE(algo::any_of(vector.begin(), vector.end(), [](int value){return value == -42;}));
  ASSERT_FALSE(algo::any_of(vector.begin(), vector.end(), [](int value){return value == 0;}));

  std::array array = {6346, 3574, 737, 865, 28, 58, 2, 8658, 2, 8653735, 357848, 336};
  ASSERT_TRUE(algo::any_of(array.begin(), array.end(), [](int value){return value == 865;}));
  ASSERT_TRUE(algo::any_of(array.begin(), array.end(), [](int value){return value == 8653735;}));
  ASSERT_FALSE(algo::any_of(array.begin(), array.end(), [](int value){return value == -42;}));
  ASSERT_FALSE(algo::any_of(array.begin(), array.end(), [](int value){return value == 0;}));
  
  std::deque deque = {6346, 3574, 737, 865, 28, 58, 2, 8658, 2, 8653735, 357848, 336};
  ASSERT_TRUE(algo::any_of(deque.begin(), deque.end(), [](int value){return value == 865;}));
  ASSERT_TRUE(algo::any_of(deque.begin(), deque.end(), [](int value){return value == 8653735;}));
  ASSERT_FALSE(algo::any_of(deque.begin(), deque.end(), [](int value){return value == -42;}));
  ASSERT_FALSE(algo::any_of(deque.begin(), deque.end(), [](int value){return value == 0;}));

  std::list list = {6346, 3574, 737, 865, 28, 58, 2, 8658, 2, 8653735, 357848, 336};
  ASSERT_TRUE(algo::any_of(list.begin(), list.end(), [](int value){return value == 865;}));
  ASSERT_TRUE(algo::any_of(list.begin(), list.end(), [](int value){return value == 8653735;}));
  ASSERT_FALSE(algo::any_of(list.begin(), list.end(), [](int value){return value == -42;}));
  ASSERT_FALSE(algo::any_of(list.begin(), list.end(), [](int value){return value == 0;}));
}

TEST(AlgorithmsTestSuite, none_of) {

  std::vector vector = {-236, -3463, 35634, 347, 2624, -363, 3426, -7435, -345, 26247, 3473};
  ASSERT_TRUE(algo::none_of(vector.begin(), vector.end(), [](int value){return value == -6236;}));
  ASSERT_TRUE(algo::none_of(vector.begin(), vector.end(), [](int value){return value == -228;}));
  ASSERT_FALSE(algo::none_of(vector.begin(), vector.end(), [](int value){return value = 35634;}));
  ASSERT_FALSE(algo::none_of(vector.begin(), vector.end(), [](int value){return value = -363;}));

  std::array array = {-236, -3463, 35634, 347, 2624, -363, 3426, -7435, -345, 26247, 3473};
  ASSERT_TRUE(algo::none_of(array.begin(), array.end(), [](int value){return value == -6236;}));
  ASSERT_TRUE(algo::none_of(array.begin(), array.end(), [](int value){return value == -228;}));
  ASSERT_FALSE(algo::none_of(array.begin(), array.end(), [](int value){return value == 35634;}));
  ASSERT_FALSE(algo::none_of(array.begin(), array.end(), [](int value){return value == -363;}));
  
  std::deque deque = {-236, -3463, 35634, 347, 2624, -363, 3426, -7435, -345, 26247, 3473};
  ASSERT_TRUE(algo::none_of(deque.begin(), deque.end(), [](int value){return value == -6236;}));
  ASSERT_TRUE(algo::none_of(deque.begin(), deque.end(), [](int value){return value == -228;}));
  ASSERT_FALSE(algo::none_of(deque.begin(), deque.end(), [](int value){return value == 35634;}));
  ASSERT_FALSE(algo::none_of(deque.begin(), deque.end(), [](int value){return value == -363;}));

  std::list list = {-236, -3463, 35634, 347, 2624, -363, 3426, -7435, -345, 26247, 3473};
  ASSERT_TRUE(algo::none_of(list.begin(), list.end(), [](int value){return value == -6236;}));
  ASSERT_TRUE(algo::none_of(list.begin(), list.end(), [](int value){return value == -228;}));
  ASSERT_FALSE(algo::none_of(list.begin(), list.end(), [](int value){return value == 35634;}));
  ASSERT_FALSE(algo::none_of(list.begin(), list.end(), [](int value){return value == -363;}));
}

TEST(AlgorithmsTestSuite, one_of) {

  std::vector vector = {6326, 247346, 262473, -26, -26, 0, 3462, -233, 1, 2, 2, 36246, 753634, -64372};
  ASSERT_TRUE(algo::one_of(vector.begin(), vector.end(), [](int value){return value == 6326;}));
  ASSERT_TRUE(algo::one_of(vector.begin(), vector.end(), [](int value){return value == 262473;}));
  ASSERT_FALSE(algo::one_of(vector.begin(), vector.end(), [](int value){return value == -26;}));
  ASSERT_FALSE(algo::one_of(vector.begin(), vector.end(), [](int value){return value == 2;}));

  std::array array = {6326, 247346, 262473, -26, -26, 0, 3462, -233, 1, 2, 2, 36246, 753634, -64372};
  ASSERT_TRUE(algo::one_of(array.begin(), array.end(), [](int value){return value == 6326;}));
  ASSERT_TRUE(algo::one_of(array.begin(), array.end(), [](int value){return value == 262473;}));
  ASSERT_FALSE(algo::one_of(array.begin(), array.end(), [](int value){return value == -26;}));
  ASSERT_FALSE(algo::one_of(array.begin(), array.end(), [](int value){return value == 2;}));
  
  std::deque deque = {6326, 247346, 262473, -26, -26, 0, 3462, -233, 1, 2, 2, 36246, 753634, -64372};
  ASSERT_TRUE(algo::one_of(deque.begin(), deque.end(), [](int value){return value == 6326;}));
  ASSERT_TRUE(algo::one_of(deque.begin(), deque.end(), [](int value){return value == 262473;}));
  ASSERT_FALSE(algo::one_of(deque.begin(), deque.end(), [](int value){return value == -26;}));
  ASSERT_FALSE(algo::one_of(deque.begin(), deque.end(), [](int value){return value == 2;}));

  std::list list = {6326, 247346, 262473, -26, -26, 0, 3462, -233, 1, 2, 2, 36246, 753634, -64372};
  ASSERT_TRUE(algo::one_of(list.begin(), list.end(), [](int value){return value == 6326;}));
  ASSERT_TRUE(algo::one_of(list.begin(), list.end(), [](int value){return value == 262473;}));
  ASSERT_FALSE(algo::one_of(list.begin(), list.end(), [](int value){return value == -26;}));
  ASSERT_FALSE(algo::one_of(list.begin(), list.end(), [](int value){return value == 2;}));
}

TEST(AlgorithmsTestSuite, is_sorted) {

  std::vector vector = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70};
  ASSERT_TRUE(algo::is_sorted(vector.begin(), vector.end(), [](int value1, int value2){return value1 > value2;}));
  ASSERT_FALSE(algo::is_sorted(vector.begin(), vector.end(), [](int value1, int value2){return value1 < value2;}));

  std::array array = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70};
  ASSERT_TRUE(algo::is_sorted(array.begin(), array.end(), [](int value1, int value2){return value1 > value2;}));
  ASSERT_FALSE(algo::is_sorted(array.begin(), array.end(), [](int value1, int value2){return value1 < value2;}));
  
  std::deque deque = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70};
  ASSERT_TRUE(algo::is_sorted(deque.begin(), deque.end(), [](int value1, int value2){return value1 > value2;}));
  ASSERT_FALSE(algo::is_sorted(deque.begin(), deque.end(), [](int value1, int value2){return value1 < value2;}));

  std::list list = {90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70};
  ASSERT_TRUE(algo::is_sorted(list.begin(), list.end(), [](int value1, int value2){return value1 > value2;}));
  ASSERT_FALSE(algo::is_sorted(list.begin(), list.end(), [](int value1, int value2){return value1 < value2;}));
}

TEST(AlgorithmsTestSuite, is_partitioned) {

  std::vector vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_TRUE(algo::is_partitioned(vector.begin(), vector.end(), [](int value){return value > 5;}));
  ASSERT_TRUE(algo::is_partitioned(vector.begin(), vector.end(), [](int value){return value < 5;}));
  ASSERT_FALSE(algo::is_partitioned(vector.begin(), vector.end(), [](int value){return value > -1;}));
  ASSERT_FALSE(algo::is_partitioned(vector.begin(), vector.end(), [](int value){return value < 11;}));

  std::array array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_TRUE(algo::is_partitioned(array.begin(), array.end(), [](int value){return value > 5;}));
  ASSERT_TRUE(algo::is_partitioned(array.begin(), array.end(), [](int value){return value < 5;}));
  ASSERT_FALSE(algo::is_partitioned(array.begin(), array.end(), [](int value){return value > -1;}));
  ASSERT_FALSE(algo::is_partitioned(array.begin(), array.end(), [](int value){return value < 11;}));
  
  std::deque deque = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_TRUE(algo::is_partitioned(deque.begin(), deque.end(), [](int value){return value > 5;}));
  ASSERT_TRUE(algo::is_partitioned(deque.begin(), deque.end(), [](int value){return value < 5;}));
  ASSERT_FALSE(algo::is_partitioned(deque.begin(), deque.end(), [](int value){return value > -1;}));
  ASSERT_FALSE(algo::is_partitioned(deque.begin(), deque.end(), [](int value){return value < 11;}));

  std::list list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_TRUE(algo::is_partitioned(list.begin(), list.end(), [](int value){return value > 5;}));
  ASSERT_TRUE(algo::is_partitioned(list.begin(), list.end(), [](int value){return value < 5;}));
  ASSERT_FALSE(algo::is_partitioned(list.begin(), list.end(), [](int value){return value > -1;}));
  ASSERT_FALSE(algo::is_partitioned(list.begin(), list.end(), [](int value){return value < 11;}));
}

TEST(AlgorithmsTestSuite, find_not) {

  std::vector vector = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_not(vector.begin(), vector.end(), 777), vector.begin());
  ASSERT_EQ(algo::find_not(vector.begin(), vector.end(), 253), vector.begin() + 1);
  ASSERT_FALSE(algo::find_not(vector.begin(), vector.end(), 5325) == vector.begin() + 1);
  ASSERT_FALSE(algo::find_not(vector.begin(), vector.end(), 2) == vector.begin() + 1);

  std::array array = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_not(array.begin(), array.end(), 777), array.begin());
  ASSERT_EQ(algo::find_not(array.begin(), array.end(), 253), array.begin() + 1);
  ASSERT_FALSE(algo::find_not(array.begin(), array.end(), 5325) == array.begin() + 1);
  ASSERT_FALSE(algo::find_not(array.begin(), array.end(), 2) == array.begin() + 1);
  
  std::deque deque = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_not(deque.begin(), deque.end(), 777), deque.begin());
  ASSERT_EQ(algo::find_not(deque.begin(), deque.end(), 253), deque.begin() + 1);
  ASSERT_FALSE(algo::find_not(deque.begin(), deque.end(), 5325) == deque.begin() + 1);
  ASSERT_FALSE(algo::find_not(deque.begin(), deque.end(), 2) == deque.begin() + 5);
}

TEST(AlgorithmsTestSuite, find_backward) {

  std::vector vector = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_backward(vector.begin(), vector.end(), 777), vector.end() - 4);
  ASSERT_EQ(algo::find_backward(vector.begin(), vector.end(), 3), vector.end() - 7);
  ASSERT_FALSE(algo::find_backward(vector.begin(), vector.end(), 262462) == vector.end() - 9);
  ASSERT_FALSE(algo::find_backward(vector.begin(), vector.end(), 5325) == vector.end() - 14);

  std::array array = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_backward(array.begin(), array.end(), 777), array.end() - 4);
  ASSERT_EQ(algo::find_backward(array.begin(), array.end(), 3), array.end() - 7);
  ASSERT_FALSE(algo::find_backward(array.begin(), array.end(), 262462) == array.end() - 9);
  ASSERT_FALSE(algo::find_backward(array.begin(), array.end(), 5325) == array.end() - 14);
  
  std::deque deque = {253, 5325, 64362, 73734, 63463, 34636, 262462, 1, 2, 3, 3, 4, 777, 777, 11, 1624, 1624};
  ASSERT_EQ(algo::find_backward(deque.begin(), deque.end(), 777), deque.end() - 4);
  ASSERT_EQ(algo::find_backward(deque.begin(), deque.end(), 3), deque.end() - 7);
  ASSERT_FALSE(algo::find_backward(deque.begin(), deque.end(), 262462) == deque.end() - 9);
  ASSERT_FALSE(algo::find_backward(deque.begin(), deque.end(), 5325) == deque.end() - 14);
}

TEST(AlgorithmsTestSuite, is_palindrome) {

  std::vector vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  ASSERT_TRUE(algo::is_palindrome(vector.begin(), vector.end(), [](int value){return value == 10;}));
  ASSERT_TRUE(algo::is_palindrome(vector.begin(), vector.end(), [](int value){return value != 10;}));
  ASSERT_FALSE(algo::is_palindrome(vector.begin(), vector.end(), [](int value){return value > 5;}));
  ASSERT_FALSE(algo::is_palindrome(vector.begin(), vector.end(), [](int value){return value < 14;}));

  std::array array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  ASSERT_TRUE(algo::is_palindrome(array.begin(), array.end(), [](int value){return value > 0;}));
  ASSERT_TRUE(algo::is_palindrome(array.begin(), array.end(), [](int value){return value < 21;}));
  ASSERT_FALSE(algo::is_palindrome(array.begin(), array.end(), [](int value){return value > 6;}));
  ASSERT_FALSE(algo::is_palindrome(array.begin(), array.end(), [](int value){return value < 18;}));
  
  std::deque deque = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  ASSERT_TRUE(algo::is_palindrome(deque.begin(), deque.end(), [](int value){return value == 6;}));
  ASSERT_TRUE(algo::is_palindrome(deque.begin(), deque.end(), [](int value){return value != 6;}));
  ASSERT_FALSE(algo::is_palindrome(deque.begin(), deque.end(), [](int value){return value > 2;}));
  ASSERT_FALSE(algo::is_palindrome(deque.begin(), deque.end(), [](int value){return value < 10;}));
}
