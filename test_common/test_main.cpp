#include <QtTest>

#if defined(BINARY_SEARCH)
#include <test_node_binary_search.h>
#elif defined(HASH_TABLE)
#include <test_node_hash_table.h>
#elif defined(EXTENSIVE_TREE)
#include <test_node_extensive_tree.h>
#endif

int main(int argc, char **argv) {
    TestNode *testNode = nullptr;
#if defined(BINARY_SEARCH)
    testNode = new TestNodeBinarySearch;
#elif defined(HASH_TABLE)
    testNode = new TestNodeHashTable;
#elif defined(EXTENSIVE_TREE)
    testNode = new TestNodeExtensiveTree;
#endif
    int result = 0;
    result |= QTest::qExec(testNode, argc, argv);
    delete testNode;
    return result;
}
