#include "ListNode.h"
ListNode::ListNode(const OperationalAmplifier& amp)
    : data(amp), next(nullptr), prev()
{
}
void ListNode::setNext(const std::shared_ptr<ListNode>& node)
{
    next = node;
    if (node) {
        node->prev = shared_from_this();
    }
}
std::shared_ptr<ListNode> ListNode::getPrev() const
{
    return prev.lock(); 
}
