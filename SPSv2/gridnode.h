#ifndef GRIDNODE_H
#define GRIDNODE_H

// Highest level of class hierarchy that describes the components of a microgrid
class gridNode
{
public:
    gridNode();
};

// Derived class from gridNode, with specific info relevant to grid edges.
// Grid edges contain information on transmission cabling, power converters, etc.
class gridEdge : public gridNode{

};

// Derived class from gridNode, with specific info relevant to elements within a microgrid.
// Elements are components like AC machines, energy storage modules, resistive heaters, etc.
class gridElement : public gridNode{

};

// Derived class from gridElement, with specific info relevant to sources (gensets)
class sourceNode : public gridElement{

};

// Derived class from gridElement, with specific info relevant to sinks (loads)
class sinkNode : public gridElement{

};

// Derived class from gridElement, with specific info relevant to energy storage modules
class esmNode : public gridElement{

};

// Derived class from gridElement, with specific info relevant to filters
class filterNode : public gridElement{

};

#endif // GRIDNODE_H
