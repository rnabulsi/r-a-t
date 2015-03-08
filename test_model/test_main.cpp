#include <QtTest>

#if defined(BINARY_SEARCH)
#include <test_node_binary_search.h>
#elif defined(HASH_TABLE)
#include <test_node_hash_table.h>
#elif defined(EXTENSIVE_TREE)
#include <test_node_extensive_tree.h>
#endif
#include <test_letternode.h>

int main(int argc, char **argv) {
    int result = 0;

    TestNode *testNode = nullptr;
#if defined(BINARY_SEARCH)
    testNode = new TestNodeBinarySearch;
#elif defined(HASH_TABLE)
    testNode = new TestNodeHashTable;
#elif defined(EXTENSIVE_TREE)
    testNode = new TestNodeExtensiveTree;
#endif
    result |= QTest::qExec(testNode, argc, argv);
    result |= QTest::qExec(QSharedPointer<TestLetterNode>::create().data(), argc, argv);
    delete testNode;
    return result;
}
