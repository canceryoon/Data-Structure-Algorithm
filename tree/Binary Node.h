#ifndef BINARY_NODE_H
#define BINARY_NODE_H
class Node
{
private:
    char data;
    Node* LChiled;
    Node* RChiled;
public:
    Node()
    {
        this->data = '\0';
        this->LChiled = NULL;
        this->RChiled = NULL;
    }
    Node(char _data)
    {
        this->data = _data;
        this->LChiled = NULL;
        this->RChiled = NULL;
    }
    char getData();
    void setData(char _data);

    void setLC(Node* lNode);
    void setRC(Node* rNode);
    Node* getLC();
    Node* getRC();
    void insertNode(int level, int addr, int depth, Node* inode);
    void printNode(int depth);
};
#endif
