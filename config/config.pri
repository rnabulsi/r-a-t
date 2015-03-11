# General compiler options
# Set standard to c++11 and turn all warnings.
CONFIG += c++11
CONFIG += warn_on
QMAKE_CFLAGS += -Wall -Wextra -Wmissing-braces
QMAKE_CXXFLAGS += -Wall -Wextra -Wmissing-braces

# Enable dependency tracking
CONFIG += create_prl
CONFIG += link_prl

# Node class configuration. Look at class documentation for details.
#
# Possible values: BINARY_SEARCH, HASH_TABLE, EXTENSIVE_TREE
#
# Values are mutualy exclusive and prioritized in the order given above.
# The node class has to be configured or the compilation will fail.
DEFINES += EXTENSIVE_TREE

# ResultNode class configuration. Look at class documentation for details.
#
# Possible value: REDUCE_THRU_DIACRITICS
#
# Value can be not defined too, causing default implementation of ResultNode
# to be compiled.
DEFINES += REDUCE_THRU_DIACRITICS
