#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

struct PrintPermutation
{
    template <typename Iter> auto
    operator () (Iter first, Iter last) const -> void
    {
        std::cout << "[ " ;
        while (first != last) {
            std::cout << *first << " " ;
            ++ first ;
        }
        std::cout << "]" << std::endl ;
    }
} ;

struct IsWhitespace
{
    template <typename Char> auto
    operator () (Char c) const -> bool
    {
        return (c == ' ' )
            || (c == '\n')
            || (c == '\r')
            || (c == '\t')
            || (c == '\f')
            || (c == '\v') ;
    }
} ;

template <typename String> inline auto
remove_whitespaces (String text) -> String
{
    text.erase
        ( std::remove_if
            ( text.begin ()
            , text.end ()
            , IsWhitespace () )
        , text.end () ) ;
    return text ;
}

template <typename Iter> auto
find_longest_non_increasing_suffix (Iter first, Iter last) -> Iter
{
    if (first == last) return last ;
    Iter back = std::prev (last) ;
    if (back == first) return last ;
    do {
        -- last ;
        -- back ;
    } while ((first != last) && (*back >= *last)) ;
    return last ;
}

template <typename Iter> auto
find_rightmost_successor (Iter first, Iter second, Iter last) -> Iter
{
    if (second == last) return last ;
    do {
        -- last ;
    } while ((second != last) && (*last <= *first)) ;
    return last ;
}

template <typename Iter> auto
next_permutation (Iter first, Iter last) -> bool
{
    if (first == last) return false ;
    Iter suffix = find_longest_non_increasing_suffix (first, last) ;
    if (suffix == first) return false ;
    if (suffix == last)  return false ;
    Iter pivot = std::prev (suffix) ;
    Iter successor = find_rightmost_successor (pivot, suffix, last) ;
    std::iter_swap (pivot, successor) ;
    std::reverse (suffix, last) ;
    return true ;
}

template <typename Iter, typename Function> inline auto
permutations_iter (Iter first, Iter last, Function driver) -> void
{
    if (first == last) return ;
    std::sort (first, last) ;
    do {
        driver (first, last) ;
    } while (::next_permutation (first, last)) ;
    return ;
}

template <typename String, typename Function> inline auto
permutations (String text, Function driver) -> void
{
    permutations_iter (std::begin (text), std::end (text), driver) ;
}

template <typename String, typename InStream> inline auto
read_text_from_stdin (InStream& in) -> String
{
    std::istreambuf_iterator <char> begin (in), end ;
    std::string text (begin, end) ;
    text = remove_whitespaces (text) ;
    return text ;
}

int main (int argc, char const *argv [])
{
    std::string text = read_text_from_stdin <std::string> (std::cin) ;
    permutations (text, PrintPermutation ()) ;
    return 0 ;
}
