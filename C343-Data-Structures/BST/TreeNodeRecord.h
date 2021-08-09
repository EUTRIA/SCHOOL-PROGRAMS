#pragma once
template <class T>
class TreeNodeRecord{
public:
    T value;
    TreeNodeRecord<T>* left;
    TreeNodeRecord<T>* right;
    TreeNodeRecord<T>* parent;
};

