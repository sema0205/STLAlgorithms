#include <iterator>
#include <concepts>

namespace algo {

    template<typename InputIterator, typename Compare>
    bool all_of(InputIterator first, InputIterator last, Compare comp) {
        
        while (first != last) {
            if (!comp(*first)) {
                return false;
            }

            ++first;
        }

        return true;
    }

    template<typename InputIterator, typename Compare>
    bool any_of(InputIterator first, InputIterator last, Compare comp) {

        while (first != last) {
            if (comp(*first)) {
                return true;
            }

            ++first;
        }

        return false;
    }

    template<typename InputIterator, typename Compare>
    bool none_of(InputIterator first, InputIterator last, Compare comp) {
        
        while (first != last) {
            if (comp(*first)) {
                return false;
            }
        
            ++first;
        }

        return true;
    }

    template<typename InputIterator, typename Compare>
    bool one_of(InputIterator first, InputIterator last, Compare comp) {

        bool single = false;

        while (first != last) {
            if (comp(*first)) {
                if (single) {
                    return false;
                } else {
                    single = true;
                }
            }

            ++first;
        }

        return single ? true : false;
    }

    template<typename ForwardIterator, typename Compare>
    bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp) {

        ForwardIterator current = first;
        ++first;

        while (first != last) {
            if (!comp(*current, *first)) {
                return false;
            }

            current = first;
            ++first;
        }

        return true;
    }


    template<typename ForwardIterator, typename Compare>
    bool is_partitioned(ForwardIterator first, ForwardIterator last, Compare comp) {

        bool cur = comp(*first);
        int changed = 0;

        while(first != last) {
            if (cur) {
                if (!comp(*first)) {
                    cur = false;
                    changed++;
                }
            } else {
                if (comp(*first)) {
                    cur = true;
                    changed++;
                }
            }
            ++first;
        }

        return changed == 1 ? true : false;
    }

    template<typename InputIterator, typename T>
    InputIterator find_not(InputIterator first, InputIterator last, const T& value) {

        while(first != last) {
            if (*first != value) {
                return first;
            }

            ++first;
        }

        return last;
    }

    
    template<typename ForwardIterator, typename T>
    ForwardIterator find_backward(ForwardIterator first, ForwardIterator last, const T& value) {
        
        ForwardIterator cur = last;

        while(first != last) {
            if (*first == value) {
                cur = first;
            }

            ++first;
        }

        return cur;
    }


    template<typename RandomAccessIterator, typename Compare>
    bool is_palindrome(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {

        --last;

        while(first != last && first + 1 < last) {
            if (comp(*first) != comp(*last)) {
                return false;
            }

            ++first;
            --last;
        }

        return true;
    }


    template<typename T>
    class xrangeIterator {
    public:
        
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        xrangeIterator(T val, T start, T end, T step) {
            cur_value_ = val;
            start_ = start;
            end_ = end;
            step_ = step;
        }

        T operator*() const {return cur_value_;}

        xrangeIterator& operator++() {
            if (cur_value_ + step_ >= end_ && step_ > 0 || cur_value_ + step_ <= end_ && step_ < 0) {
                cur_value_ = end_;
            } else {
                cur_value_ += step_;
            }
        
            return *this;
        }

        xrangeIterator operator++(int) {
            xrangeIterator temp(*this);
            operator++();
            return temp;
        }

        bool operator==(const xrangeIterator& other) const {
            return cur_value_ == other.cur_value_;
        }

        bool operator!=(const xrangeIterator& other) const {
            return !(*this == other);
        }

    private:
        T end_;
        T start_;
        T step_;
        T cur_value_;
    };


    template<typename T>
    class xrange {
    public:

        using iterator = xrangeIterator<T>;

        xrange(T start, T end, T step) : start_(start), end_(end), step_(step) {}
        xrange(T start, T end) : start_(start), end_(end) {}
        xrange(T end) : end_(end), start_() {}

        iterator begin() {
            return iterator(start_, start_, end_, step_);
        }

        iterator end() {
            return iterator(end_, start_, end_, step_);
        }

    private:
        T start_ = 0;
        T end_ = 0;
        T step_ = 1;
    };


    template<typename first_iterator, typename second_iterator> 
    class zipIterator {
    public:
        
        using first_value = typename first_iterator::value_type;
        using second_value = typename second_iterator::value_type;
        using iterator_category = std::input_iterator_tag;
        using difference_type = std::ptrdiff_t;


        zipIterator(const std::pair<first_iterator, second_iterator>& val, first_iterator first_beg, first_iterator first_end, 
                                                                second_iterator second_beg, second_iterator second_end) {
            first_it_ = val.first;
            second_it_ = val.second;
            first_beg_ = first_beg;
            first_end_ = first_end;
            second_beg_ = second_beg;
            second_end_ = second_end;
        }

        std::pair<first_value, second_value> operator*() {return {*first_it_, *second_it_};}

        zipIterator& operator++() {
            first_it_++;
            second_it_++;
            if (first_it_ == first_end_ || second_it_ == second_end_) {
                first_it_ = first_end_;
                second_it_ = second_end_;
            }

            return *this;
        }

        zipIterator operator++(int) {
            zipIterator temp(*this);
            operator++();
            return temp;
        }

        bool operator==(const zipIterator& other) {
            return (*first_it_ == *other.first_it_) && (*second_it_ == *other.second_it_);
        }

        bool operator!=(const zipIterator& other) {
            return !(*this == other);
        }

    private:
        first_iterator first_it_;
        second_iterator second_it_;
        first_iterator first_beg_;
        first_iterator first_end_;
        second_iterator second_beg_;
        second_iterator second_end_;
    };


    template<typename ContainerOne, typename ContainerTwo> 
    class zip {
    public:

        using first_iterator = typename ContainerOne::iterator;
        using second_iterator = typename ContainerTwo::iterator;
        using iterator = zipIterator<first_iterator, second_iterator>;

        zip(ContainerOne& first, ContainerTwo& second) {
            first_beg_ = first.begin();
            first_end_ = first.end();
            second_beg_ = second.begin();
            second_end_ = second.end();
        }

        iterator begin() {
            return iterator(std::make_pair(first_beg_, second_beg_), first_beg_, first_end_, second_beg_, second_end_);
        }

        iterator end() {
            return iterator(std::make_pair(first_end_, second_end_), first_beg_, first_end_, second_beg_, second_end_);
        }

    private:
        first_iterator first_beg_;
        first_iterator first_end_;
        second_iterator second_beg_;
        second_iterator second_end_;
    };

}