// This macro can do this:
//
//      defer(begin(), end())
//      {
//          ...
//      }
//
// meaning it runs begin() and end() before and after the code in curly brackets
//
// Source:
//      Talk: Modern C and what we can learn from it
//      url:  https://www.youtube.com/watch?v=QpAhX-gsHMs


#define concat(a, b) a ## b
#define macro_var(name) concat(name, __LINE__)
#define defer(start, end)                                                      \
    for (int macro_var(_i_) = (start, 0); !macro_var(_i_);                     \
         (macro_var(_i_) += 1), end)
