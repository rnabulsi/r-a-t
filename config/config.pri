# General compiler options
# Set standard to c++11 and turn all warnings.
CONFIG += c++11
CONFIG += warn_on
QMAKE_CFLAGS += -Wall -Wextra -Wmissing-braces
QMAKE_CXXFLAGS += -Wall -Wextra -Wmissing-braces

# Enable dependancy tracking
CONFIG += create_prl
CONFIG += link_prl

# Node class configuration. Look at class documentation for details.
#
# Possible values: BINARY_SEARCH, HASH_TABLE, EXTENSIVE_TREE
#
# Values are mutualy exclusive and prioritized in the order given above.
# The node class has to be configured or the compilation will fail.
DEFINES += BINARY_SEARCH

# LetterNode class configuration. Look at class documentation for details.
#
# Possible values:
#
# Values are mutually...
DEFINES +=
