<%
import os
from datetime import datetime
MAXARGS=int(argv[0])
today=datetime.strftime( datetime.now(), "%Y-%m-%d %H:%M:%S"  )
def genargs(n): 
    return ",".join([ "args[%d]" % j for j in range(n) ])
%>

/** 
 * Generated:  ${today}
 * Arguments:  ${" ".join(argv)}
 */

#include <vector>
#include <limits>

namespace trivial {

template <size_t N, typename... Args>
struct FnType {
    using Call = typename FnType<N - 1, double, Args...>::Call;
};

template <typename... Args>
struct FnType<0, Args...> {
    typedef double (*Call)(Args...);
};

double callfn(void* fn, const std::vector<double>& args) {
    switch (args.size()) {
% for row in range(MAXARGS+1):
        case ${row}: return FnType<${row}>::Call(fn)(${genargs(row)}); break;
% endfor
    }
    return std::numeric_limits<double>::quiet_NaN();
}

} // namespace trivial
