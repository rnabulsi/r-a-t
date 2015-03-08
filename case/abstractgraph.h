#ifndef ABSTRACTGRAPH_H
#define ABSTRACTGRAPH_H

#warning Still unimplemented
#warning Review class purpose

/*!
 * \brief The AbstractGraph class
 */
class AbstractGraph {
public:
    explicit AbstractGraph();
    virtual ~AbstractGraph();

    virtual bool empty() = 0;
};

#endif // ABSTRACTGRAPH_H
