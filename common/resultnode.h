#ifndef RESULTNODE_H
#define RESULTNODE_H

#include <QObject>
#include <node.h>

class ResultNode : public Node {
public:
    explicit ResultNode(Node *parent = nullptr) : Node(parent) {}
    virtual ~ResultNode() {}
};

#endif // RESULTNODE_H
