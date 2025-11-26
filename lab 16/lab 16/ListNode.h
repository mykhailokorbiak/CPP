#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <memory>
#include "OperationalAmplifier.h"
class ListNode : public std::enable_shared_from_this<ListNode> {
public:
    OperationalAmplifier data;
    std::shared_ptr<ListNode> next;
    std::weak_ptr<ListNode> prev;
    explicit ListNode(const OperationalAmplifier& amp);
    void setNext(const std::shared_ptr<ListNode>& node);
    std::shared_ptr<ListNode> getPrev() const;
};
#endif
