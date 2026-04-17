#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node {
    private:
        T value;
    public:
        Node(T v):value(v) {}
        T getValue();
        void setValue(T value);
};

template <typename T>
void Node<T>::setValue(T value) {
    this->value = value;
}

template<typename T>
T Node<T>::getValue() {
    return value;
}

#endif