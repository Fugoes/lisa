#ifndef LISA_LNODE_H
#define LISA_LNODE_H

#include "LNodeType.h"

#include <memory>

class LNode {
public:
    LNodeType type;

    explicit LNode(LNodeType type) {
        this->type = type;
    }

    virtual ~LNode() = default;
};

template<class T>
class LNodeData : public LNode {
public:
    T value{};

    LNodeData(LNodeType type, T &&value) : LNode(type) {
        this->value = std::move(value);
    }

    LNodeData(LNodeType type, T &value) : LNode(type) {
        this->value = value;
    }

    ~LNodeData() override = default;

};

template<class T>
static std::shared_ptr<LNodeData<T>> lnode_get(std::shared_ptr<LNode> p) {
    return std::static_pointer_cast<LNodeData<T>>(p);
}

#endif //LISA_LNODE_H
